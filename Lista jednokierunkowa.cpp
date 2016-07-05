#include <iostream>

using namespace std;

struct lista
{
	int dane;
	lista *next;
};

void usun_poczatek(lista *&head, lista *&tail)
{
	if(head==NULL && tail==NULL)
	{
		cout<<"Lista jest pusta!\n";
		return;
	}
	
	if(head->next == tail)
	{
		head=tail;
		head->next=NULL;
		tail->next=NULL;
		return;
	}
	head=head->next;
}

void usun_pozycja(lista *&head, lista *& tail, int pozycja)
{
	lista *pom=new lista;
	int licznik=0;
	
	if(pozycja==1)
	{
		head=head->next;
		return;
	}
	
	if(head==NULL && tail==NULL)
	{
		cout<<"Lista jest pusta!\n";
		return;
	}
	
	pom=head;
	
	while(pom!=tail)
	{
		licznik++;
		pom=pom->next;
	}
	licznik++;
	
	if(pozycja > licznik)
	{
		cout<<"Blad, podana pozycja wykracza poza liste!\n";
		return;
	}
	
	pom=head;
	
	for(int i=1; i<pozycja-1 ; i++)
	{
		pom=pom->next;
	}
	
	if(pom->next==tail)
	{
		tail=pom;
		tail->next=NULL;
		return;
	}
	
	pom->next=pom->next->next;
}

void usun_o_kluczu(lista *&head, lista *& tail, int klucz)
{
	lista *pom=new lista;
	
	if(head==NULL && tail==NULL)
	{
		cout<<"Lista jest pusta!\n";
		return;
	}
	
	pom=head;
	
	if(head->dane==klucz)
	{
		head=head->next;
		return;
	}
	
	if(tail->dane==klucz)
	{
		while(pom)
		{
			if(pom->next == tail)
			{
				tail=pom;
				tail->next=NULL;
				return;
			}
			pom=pom->next;
		}
	}
		
	while(pom->next->dane != klucz)
	{
		pom=pom->next;
	}

	pom->next=pom->next->next;
}

void usun_koniec(lista*& head, lista *&tail)
{
	lista *pom=new lista;
	pom=head;
	
	while(pom)
	{
		if(pom->next == tail)
		{
			tail=pom;
			tail->next=NULL;
			return;
		}
		pom=pom->next;
	}
	
}

void dodaj_na_pozycje(lista *&head, lista *& tail, int pozycja,int n)
{
	lista *nowy = new lista;
	nowy->dane=n;
	lista *pom=new lista;
	lista *pom2=new lista;
	
	pom=head;
	
	if(head==NULL && tail==NULL)
	{
		cout<<"Lista jest pusta!\n";
		return;
	}
	
	for(int i=1; i<pozycja-1; i++)
	{
		if(pom->next==NULL)
		{
			cout<<"Blad, pozycja wychodzi poza dlugosc listy! Wartosc, ktora nie zostala dodana to: "<<n<<endl;
			return;
		}
		pom=pom->next;
	}
	
	pom2=pom->next;
	pom->next=nowy;
	pom=pom->next;
	pom->next=pom2;
}

void dodaj_przed_klucz(lista *&head, lista *& tail, int klucz,int n)
{
	lista *nowy = new lista;
	nowy->dane=n;
	lista *pom=new lista;
	lista *pom2=new lista;
	
	if (head == NULL && tail == NULL)
	{
		cout<<"Blad, lista jest przeciez pusta!!\n";
		return;
	}
	
	pom=head;
	
	if (head->dane == klucz)
	{
		pom=nowy;
		pom->next=head;
		head=pom;
		return;
	}
	
	while(1)
		{
			if(pom->next->dane == klucz)	
			{
				pom2=pom->next;
				pom->next=nowy;
				pom=pom->next;
				pom->next=pom2;
				return;
			}
			
			pom=pom->next;
		}
}

void dodaj_na_koniec(lista *&head, lista *& tail, int n)
{
	lista *nowy = new lista;
	nowy->dane=n;
	
	if (head == NULL & tail == NULL)
	{
		head=nowy;
		tail=nowy;
		tail->next=NULL;
	}
	else
	{
	tail->next=nowy;
	tail=tail->next;
	tail->next=NULL;
	}
}

void dodaj_na_poczatek(lista *&head, lista *& tail, int n)
{
	lista *nowy = new lista;
	nowy->dane=n;
	lista *pom=new lista;
	
	if (head == NULL & tail == NULL)
	{
		head=nowy;
		tail=nowy;
		tail->next=NULL;
		return;
	}
	
	pom=nowy;
	pom->next=head;
	head=pom;
	
}

void dodaj_sort(lista *&head, lista *& tail, int n)
{
	lista *nowy = new lista;
	nowy->dane=n;
	lista *pom=new lista;
	lista *pom2=new lista;
	
	if(head->dane > nowy->dane)
	{
		pom=nowy;
		pom->next=head;
		head=pom;
		return ;
	}
	
	pom=head;
	
	if (head == NULL & tail == NULL)
	{
		head=nowy;
		tail=nowy;
		tail->next=NULL;
	}
	
	if(nowy->dane > tail->dane)
	{
		tail->next=nowy;
		tail=tail->next;
		tail->next=NULL;
		return;
	}
	
	else
	{
		while(1)
		{
			if(nowy->dane <= pom->next->dane)
			{
				pom2=pom->next;
				pom->next=nowy;
				pom=pom->next;
				pom->next=pom2;
				return;
			}
			
			pom=pom->next;
		}
	}
}

void odwroc(lista *&head, lista *&tail)
{
	lista *pom=new lista;
	lista *pom2=new lista;
	
	if (head == NULL && tail == NULL)
	{
		cout<<"Lista jest pusta !!\n";
		return;
	}
	
	pom->next=head;
	pom2=head;
	
	while(pom2->next!=NULL)
	{
		pom=pom2->next;
		pom2->next=pom->next;
		pom->next=head;
		head=pom;
	}
}

void show(lista *head)
{
	cout<<"Dane na Twojej liscie to: ";
	while(head)
	{
		cout<<head->dane<<" ";
		head=head->next;
	}
	cout<<endl;
}

int main()
{
	lista * head=NULL;
	lista * tail=NULL;
	
	dodaj_na_koniec(head,tail,6);
	dodaj_na_koniec(head,tail,65);
	dodaj_na_koniec(head,tail,90);
	dodaj_na_koniec(head,tail,3);
	dodaj_sort(head,tail,2);
	dodaj_sort(head,tail,1);
	dodaj_sort(head,tail,5);
	dodaj_sort(head,tail,5);
	dodaj_sort(head,tail,200);
	dodaj_na_poczatek(head,tail,8);
	dodaj_przed_klucz(head,tail,5,9);
	dodaj_na_pozycje(head,tail,5,3);
	usun_koniec(head,tail);
	usun_o_kluczu(head,tail,9);
	usun_pozycja(head,tail,3);
	odwroc(head,tail);
	
	show(head);
	
	
	return 0;
}
