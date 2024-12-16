#ifndef s21_calc
#define s21_calc

#ifdef __cplusplus
extern "C" {
#endif

typedef struct s21_linked_list {
  int type;
  double num;
  char sign;
  struct s21_linked_list* next;
  struct s21_linked_list* prev;
} s21_linked_list;

typedef struct s21_bank_blank {
  long double mpai;  // monthly payment or accrued interest
  long double toll;
  long double total_payout;
  // for diff
  long double body_payment;  // body of monthly payment
  long double remaining_debt;

} s21_bank;

s21_linked_list* s21_create_node(double num, char sign, int type);
s21_linked_list* s21_add_node(s21_linked_list* node, double num, char sign,
                              int type);
s21_linked_list* s21_get_last(s21_linked_list* head);
void s21_del_last(s21_linked_list* head);
void s21_clear(s21_linked_list* head);
// void s21_print_list(s21_linked_list* head);
s21_linked_list* s21_del_node(s21_linked_list* node);

int s21_validator(s21_linked_list* head);

s21_linked_list* s21_polish_notanion(s21_linked_list* head);
int s21_copy_head(s21_linked_list* head, s21_linked_list* clone);
void s21_put_sign(s21_linked_list** tail_stack, s21_linked_list** tail_signs);

int s21_calculator(s21_linked_list* head, double* res);

s21_bank* s21_credit(long double loan, int term, double rate, int type,
                     int month, s21_bank* blank);
void s21_deposit(long double depos, int term, double percent, double tax,
                 int frequency, int Capitalization);

#ifdef __cplusplus
}
#endif

#endif
