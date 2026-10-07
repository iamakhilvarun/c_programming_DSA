#include <stdio.h>

struct Employee {
  char name[50];
  int id, basic_salary;
  float hra_percent, dra_percent;
  char designation[50];
  float hra, dra, gross_salary;
};
int main() {
  int n;
  printf("Enter the number of employee: %d", n);
  scanf("%d", &n);
  struct Employee emp[n];

  for (int i = 0; i < n; i++) {
    printf("\n Employee %d\n", i + 1);

    printf("Enter the employee name:");
    scanf("%s", emp[i].name);

    printf("Enter the id: ");
    scanf("%d", &emp[i].id);

    printf("Enter the basic_salary: ");
    scanf("%d", &emp[i].basic_salary);

    printf("Enter the hra_percent: ");
    scanf("%f", &emp[i].hra_percent);

    printf("Enter the dra_percent: ");
    scanf("%f", &emp[i].dra_percent);

    printf("Enter the employee designation: ");
    scanf("%s", emp[i].designation);

    // calculation part -->
    emp[i].hra = emp[i].basic_salary * emp[i].hra_percent / 100;
    emp[i].dra = emp[i].basic_salary * emp[i].dra_percent / 100;

    emp[i].gross_salary = emp[i].basic_salary + emp[i].hra + emp[i].dra;

    printf("--------------Employee details-----------------");
    printf("\nName: %s\n", emp[i].name);
    printf("Id: %d\n", emp[i].id);
    printf("Designation: %s\n", emp[i].designation);
    printf("basic_salary: %.2d\n", emp[i].basic_salary);
    printf("hra: %.2f\n", emp[i].hra);
    printf("dra: %.2f\n", emp[i].dra);
    printf("gross_salary: %.2f", emp[i].gross_salary);
  }
  return 0;
}