#include "bits/stdc++.h"
using namespace std;
typedef struct per {
  string name;
  int age, worth;
  per(string& name, int& age, int& worth)
      : name(name), age(age), worth(worth) {}
};

int main() {
  vector<per> personList;
  int nPerson, nCase;
  string temName;
  int temAge, temWorth;
  cin >> nPerson >> nCase;
  for (int i = 0; i < nPerson; i++) {
    cin >> temName;
    scanf("%d%d", &temAge, &temWorth);
    personList.push_back(per(temName, temAge, temWorth));
  }

  sort(personList.begin(), personList.end(), [](per& x, per& y) -> bool {
    if (x.worth != y.worth) {
      return x.worth > y.worth;
    } else if (x.age != y.age) {
      return x.age < y.age;
    } else
      return x.name < y.name;
  });

  for (int i = 0; i < nCase; i++) {
    int ageS, ageE, ageN;
    cin >> ageN >> ageS >> ageE;

    printf("Case #%d:\n", i + 1);
    int k=0;
    for (int j = 0; j < personList.size(); j++) {
      if (personList[j].age >= ageS && personList[j].age <= ageE) {
        cout << personList[j].name << " " << personList[j].age << " "
             << personList[j].worth;
        printf("\n");
        if(++k==ageN){
            break;
        }
      }
    }
    if (k==0) {
      printf("None\n");
    }
  }
  return 0;
}