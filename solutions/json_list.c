#include "json_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

JObject* parse_json(const char *filename) {
    json_t *root;
    json_error_t error;

    root = json_load_file(filename, 0, &error);
    if (!root || !json_is_array(root)) {
        fprintf(stderr, "Error loading JSON: %s\n", error.text);
        return NULL;
    }

    JObject *head = NULL;
    JObject *tail = NULL;

    size_t index;
    json_t *value;
    json_array_foreach(root, index, value) {
        json_t *name_json = json_object_get(value, "name");
        json_t *age_json  = json_object_get(value, "age");

        if (!json_is_string(name_json) || !json_is_integer(age_json)) continue;

        JObject *node = malloc(sizeof(JObject));
        node->name = strdup(json_string_value(name_json));
        node->age  = json_integer_value(age_json);
        node->next = NULL;

        if (!head) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    json_decref(root);
    return head;
}

void print_list(JObject *head) {
    for (JObject *p = head; p != NULL; p = p->next) {
        printf("Name: %s, Age: %d\n", p->name, p->age);
    }
}

void free_list(JObject *head) {
    while (head) {
        JObject *tmp = head;
        head = head->next;
        free(tmp->name);
        free(tmp);
    }
}
