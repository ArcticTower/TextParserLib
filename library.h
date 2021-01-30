#ifndef TREETAGSLINKS_LIBRARY_H
#define TREETAGSLINKS_LIBRARY_H
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>
typedef struct FNNode{
    char * filename;
    struct FNNode* next;
}FNNode;

typedef struct Tree{
    long id;
    char littera;
    struct Tree* brother;
    struct Tree* child;
    FNNode* first_node;
}Tree;

typedef struct Id_line{
    Tree* node;
    struct Id_line* next;
    struct Id_line* prev;
    long bro_id;
    long child_id;
}Id_line;
int save_current_tree_file_names(Tree* current, FILE* file, long int* mov);
int save_current_tree(Tree* current, FILE* file, long int* mov);
int save_tree_to_file_first_time(Tree* root, char* file_name_id, char* file_name_strings);
int load_ids_to_line(Id_line** last_node, FILE* file_ids);
int find_id_in_line(long int id, Id_line** id_line);
int load_strings_to_trees_in_node(Id_line* idLine, FILE* file_strings);
int load_tree(Tree* root, Id_line* id_line);
int load_tree_from_file(Tree** root, char* file_ids, char* file_strings);
int is_char_ok(char ch, char* allowed_chars);
int add_word_to_tree(const char *word, int len,char* file_name,Tree** root);
int add_id_to_tree(Tree* root);
int make_tree_from_file_with_text(Tree** root,char* name_file_with_text, char* allowed_chars);
int find_word(Tree* root, char* word, FNNode** node_ptr);
int free_node(FNNode* node);
int free_tree(Tree* root);


#endif //TREETAGSLINKS_LIBRARY_H