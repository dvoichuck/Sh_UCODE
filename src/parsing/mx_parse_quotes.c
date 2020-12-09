//
// Created by Dima Voichuck on 11/27/20.
//

#include "ush.h"

static void add_extra_spase(t_ush *ush, char ch) {
    char *tmp = NULL;

    if (ch == 10)
        tmp = mx_strjoin(ush->str_input, "\\n");
    else if (ch == 9)
        tmp = mx_strjoin(ush->str_input, "\\t");
    else if (ch == 7)
        tmp = mx_strjoin(ush->str_input, "\\a");
    else if (ch == 8)
        tmp = mx_strjoin(ush->str_input, "\\b");
    else if (ch == 11)
        tmp = mx_strjoin(ush->str_input, "\\v");
    else if (ch == 12)
        tmp = mx_strjoin(ush->str_input, "\\f");
    else if (ch == 13)
        tmp = mx_strjoin(ush->str_input, "\\r");
    free(ush->str_input);
    ush->str_input = mx_strdup(tmp);
    free(tmp);
}

static void input_quotes(t_ush *ush, int *i, int *count_quote) {
    bool event = true;
    ush->ch = '\0';
    ush->event = false;
    write(1, "dquote> ", 8);
    while (event) {
        if (read(0, &ush->ch, 1) > 0) {
            if (ush->ch == '"') {
                event = false;
                (*count_quote)++;
            }
            else {
                if (mx_isspace(ush->ch)) {
                    add_extra_spase(ush, ush->ch);
                    (*i) += 2;
                    if (ush->ch == '\n')
                        write(1, "dquote> ", 8);
                }
                else {
                    mx_filling_str_with_input(ush, ush->ch);
                    (*i)++;
                }
            }
        }
    }
    ush->ch = '\0';
    ush->event = true;
}

void mx_parse_quotes(t_ush *ush, int *first, int *i, t_list **new_list) {
    char *str = NULL;
    int last = 0;
    int count_quotes = 0;
    (*first) = (*i) + 1;
    for (; ush->str_input[(*i)] != '\0'; (*i)++) {
        if (ush->str_input[(*i)] == '"') {
            count_quotes++;
            last = (*i);
        }
    }

    if (count_quotes % 2 == 1) {
        mx_del_char(ush->str_input, mx_strlen(ush->str_input) - 1, '\n');
        add_extra_spase(ush, '\n');
        (*i)++;
        input_quotes(ush, i, &count_quotes);
        last = (*i);
    }
    str = mx_substr(ush->str_input, (*first), last);
    mx_push_back(&(*new_list), str);
    ush->triger = 1;
    ush->count_list++;
}
