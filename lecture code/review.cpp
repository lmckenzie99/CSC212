int main() {
  /* int *p; // pointer */
  /* int b; //standard var */
  /* int a, *q, r,t; //mulitdeclaration */

  /* int var = 10; */
  /* int *ptr; */
  /* ptr = &var; //getting mem address of var and storing it in ptr */
  /* *ptr = 20; //dereference pointer ptr and assign 20 to change var from 10 to
   * 20 */

  int temp = 10;
  int value = 100;
  int *p1, *p2;

  p1 = &temp; // store address of temp to p1
  *p1 += 10;  // dereference p1 to access temp and add 10 to temp

  p2 = &value;
  *p2 += 5;

  p2 = p1;
  *p2 += 5;
}
