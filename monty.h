#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <fcntl.h>
#include <unistd.h>

#define NO_OF_INSTRUCTIONS 7

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
		int n;
		struct stack_s *prev;
		struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct args_s - Represents the state of the Monty interpreter.
 * @line_strs: An array of strings obtained by splitting the input line.
 * @line: The original input line.
 * @line_number: The line number in the input file.
 * @instruction: A pointer to the instruction structure.
 * @n_tokens: The number of tokens in the line.
 * @stream: A pointer to the input file stream.
 * @stack_length: The length of the stack.
 * @stackHead: A pointer to the head of the stack.
 * @stack: An indicator for whether to use a stack or queue.
 *
 * Description: This structure encapsulates the state of the Monty interpreter,
 * providing information about the input line, file stream, instruction, stack,
 * and other relevant details needed for processing Monty bytecode.
 */

typedef struct args_s
{
	char **line_strs;
	char *line;
	unsigned int line_number;
	instruction_t *instruction;
	int n_tokens;
	FILE *stream;
	int stack_length;
	stack_t *stackHead;
	int stack;
} args_t;

extern args_t *args;

void push_s(stack_t **stack, unsigned int line_number);
void pop_s(stack_t **stack, unsigned int line_number);
void pint_s(stack_t **stack, unsigned int line_number);
void pall_s(stack_t **stack, unsigned int line_number);
void swap_s(stack_t **stack, unsigned int line_number);
void add_s(stack_t **stack, unsigned int line_number);
void sub_s(stack_t **stack, unsigned int line_number);
void mul_s(stack_t **stack, unsigned int line_number);
void div_s(stack_t **stack, unsigned int line_number);
void mod_s(stack_t **stack, unsigned int line_number);
void pchar_s(stack_t **stack, unsigned int line_number);
void pstr_s(stack_t **stack, unsigned int line_number);
void rotl_s(stack_t **stack, unsigned int line_number);
void nop_s(stack_t **stack, unsigned int line_number);

void check_num_of_args(int argc);
void read_fails(char *fileName);
void malloc_fails(void);
void free_all_arguments(void);
void free_argss(void);
void free_tokenz(void);
void free_stack_s(stack_t *head);
void delete_node(void);
void close_stream(void);
void set_stream(char *fileName);
void set_Instructions(void);
void invalid_instructions(void);
void run_Instructions(void);
void free_stackHead(void);
void tokenize_s(void);
void init_args(void);


int is_number_s(char *str);


#endif /* MONTY_H */
