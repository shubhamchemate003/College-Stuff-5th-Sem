#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct rr
{
  char name[10];
  int prior;
  char state[10];
} proc[10];

int i, j, k, l, m, n;
int main()
{
  cout << "\n enter the number of processes: ";
  scanf("%d", &n);
  for (i = 0; i < n; i++)
  {
    cout << "\nenter the name of process: ";
    cin >> proc[i].name;
    cout << "\nenter the priority of process: ";
    cin >> proc[i].prior;
    strcpy(proc[i].state, "active");
  }

  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - 1; j++)
    {
      if (proc[j].prior < proc[j + 1].prior)
      {
        char ch[5];
        int t = proc[j].prior;
        proc[j].prior = proc[j + 1].prior;
        proc[j + 1].prior = t;
        strcpy(ch, proc[j].name);
        strcpy(proc[j].name, proc[j + 1].name);
        strcpy(proc[j + 1].name, ch);
      }
    }
  }
  int min = 0;
  for (i = 0; i < n; i++)
    cout << "\n"
         << proc[i].name << "\t" << proc[i].prior;
  for (i = 0; i < n; i++)
  {
    for (i = 0; i < n; i++)
    {
      if (min < proc[i].prior)
        min = proc[i].prior;
    }
  }
  for (i = 0; i < n; i++)
  {
    if (proc[i].prior == min)
    {
      cout << "\nprocess " << proc[i].name << " selected as coordinator";
      strcpy(proc[i].state, "is active");
      break;
    }
  }
  int pr;
  while (1)
  {
    int ch;
    cout << "\n\n1) election\t";
    cout << "\n2) exit  \t";
    cin >> ch;
    int max = 0;
    int ar[20];
    k = 0;
    int fl = 0;
    switch (ch)
    {
    case 1:
      char str[5];
      cout << "\n 1)initialize election\t";
      cin >> str;
      fl = 0;
    l1:
      for (i = 0; i < n; i++)
      {
        if (strcmp(str, proc[i].name) == 0)
        {
          pr = proc[i].prior;
        }
      }
      //cout<<"\n"<<pr;
      for (i = 0; i < n; i++)
      {
        if (pr < proc[i].prior)
        {
          cout << "\nprocess " << str << " send message to " << proc[i].name;
        }
      }
      for (i = 0; i < n; i++)
      {
        if (pr < proc[i].prior && strcmp(proc[i].state, "active") == 0)
        {
          if (fl == 0)
          {
            ar[k] = proc[i].prior;
            k++;
          }
          cout << "\nprocess " << proc[i].name << " send OK message to " << str;
          if (proc[i].prior > max)
            max = proc[i].prior;
        }
      }
      fl = 1;

      if (k != 0)
      {
        k = k - 1;
        for (i = 0; i < n; i++)
        {
          if (ar[k] == proc[i].prior)
            strcpy(str, proc[i].name);
        }

        goto l1;
      }
      m = 0;
      for (j = 0; j < n; j++)
      {
        if (proc[j].prior > m && strcmp(proc[j].state, "active") == 0)
        {
          cout << "\nprocess " << proc[j].name << " is select as new coordinator";
          strcpy(proc[j].state, "inactive");
          break;
        }
      }

      for (i = 0; i < n; i++)
      {
        if (strcmp(proc[i].state, "active") == 0 && proc[j].prior > proc[i].prior)
        {
          cout << "\nprocess " << proc[j].name << " send alert message to " << proc[i].name;
        }
      }

      break;
    case 2:
      exit(1);
    }
  }
  return 0;
}


