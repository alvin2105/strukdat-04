/*
Nama program	: gaji pegawai (linked list)
Nama			: Alvin
NPM				: 140810180013
tanggal			: 19 Maret 2019
Deskripsi		: SinglyList
tahun			: 2019
*/

#include<iostream>
using namespace std;

struct pegawai{

	char nama[20];
	char bidang[40];
	int gaji;
	pegawai* next;
};
typedef pegawai* pointer;
typedef pointer list;

void createlist(list& first){
	first=NULL;
}
void createData(pointer& peg){
	peg=new pegawai;
	cout<<"Masukkan nama\t: ";
	cin.ignore();
	cin.getline(peg->nama,20);
	cout<<"Masukkan bidang: ";
	cin.getline(peg->bidang,40);
	cout<<"Masukkan gaji\t: ";
	cin>>peg->gaji;
	peg->next=NULL;
	
}
void insertDepan(list& first,pointer peg){
	if(first==NULL) first=peg;
	else peg->next=first;
	first=peg;
}
void traversal(list& first){
	pointer bantu;
	if(first==NULL){
		cout<<"List kosong!"<<endl;
	}
	else{
		bantu=first;
		cout<<"Nama\t\tBidang\tGaji"<<endl;
		cout<<"========================================="<<endl;
		do{
			cout<<bantu->nama<<"\t\t"<<bantu->bidang<<"\t"<<bantu->gaji<<endl;
			bantu=bantu->next;
		}while(bantu!=NULL);
	}
}
void insertFirst(list& first,pointer peg){
	peg->next=first;
	first=peg;
}
void insertLast(list& first, pointer peg){
	pointer last=first;
	while(last->next!=NULL){
		last=last->next;
	}
	last->next=peg;
}
void deleteFirst(list& first,pointer peg){
	pointer delf=first;
	first=first->next;
	delf->next=NULL;
}
void deleteLast(list& first,pointer& pHapus){

	pointer last,precLast;

	if (first==NULL){ 
			pHapus=NULL;
			cout<<"List kosong, tidak ada yang dihapus"<<endl;
		}
	else if (first->next==NULL){ 
			first=NULL; 
		}
	else { 
			last=first; 
			precLast=NULL;
			while (last->next!=NULL){
			precLast=last; 
			last=last->next;
	}
	pHapus=last;
	precLast->next=NULL;
	}
}
int main(){
	int number;
	list first;
	pointer peg,pHapus;
	char lanjut;
		cout<<"--------DATA PEGAWAI------"<<endl;
		createlist(first);
	do{
		createData(peg);
		insertFirst(first,peg);
		cout<<"(Y/N)\t: ";
		cin>>lanjut;
	}while(lanjut=='y'||lanjut=='Y');
	do{
		cout<<endl<<endl;
		cout<<"=========================="<<endl;
		cout<<"=      SINGLY LIST       ="<<endl;
		cout<<"=========================="<<endl;
		cout<<"= 0. EXIT                ="<<endl;
		cout<<"= 1. TRAVERSAL           ="<<endl;
		cout<<"= 2. INSERT FIRST        ="<<endl;
		cout<<"= 3. INSERT LAST         ="<<endl;
		cout<<"= 4. DELETE FIRST        ="<<endl;
		cout<<"= 5. DELETE LAST         ="<<endl;
		cout<<"=========================="<<endl;
		
		cout<<"Masukkan pilihan anda\t: ";
		cin>>number;
		cout<<endl<<endl;
		switch(number){
			case 0 : return 0;
			case 1 : traversal(first);
				break;
			case 2 : do{
						createData(peg);
						insertFirst(first,peg);
						cout<<"data telah ditambah di depan"<<endl;
						cout<<"lanjut(Y/N)?: ";
						cin>>lanjut;
			}while(lanjut=='y'||lanjut=='Y');
			break;
			case 3 : do{
						createData(peg);
						insertLast(first,peg);
						cout<<"data telah ditambah di belakang"<<endl;
						cout<<"lanjut(Y/N)?: ";
						cin>>lanjut;
			}while(lanjut=='y'||lanjut=='Y');
			break;
			case 4 : do{
						deleteFirst(first,peg);
						cout<<"data pertama telah dihapus"<<endl;
						cout<<"lanjut(Y/N)?: ";
						cin>>lanjut;
			}while(lanjut=='y'||lanjut=='Y');
			break;
			case 5 : do{
						deleteLast(first,pHapus);
						cout<<"data terakhir telah dihapus"<<endl;
						cout<<"lanjut(Y/N)?: ";
						cin>>lanjut;
			}while(lanjut=='y'||lanjut=='Y');
			break;
			default : cout<<"Maaf, pilihan tidak tersedia!";
		}
	}while(lanjut!=0);
}

