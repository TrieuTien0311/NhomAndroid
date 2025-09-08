#include<stdio.h>
#include<string.h>
struct sinhvien
{
    int maSV;  
    char tenSV[50];
    char lop[10];   
    float dck;
    char hanhkiem[20];
};
struct nut
{
	sinhvien sv;
	nut *tiep;
};
nut  *BSung_S(nut *dau,nut *p)
{
	nut *tam;
	if(dau==NULL)
		dau=p;
	else
	{
		tam=dau;
		while (tam->tiep!=NULL)
			tam=tam->tiep;
					
		tam->tiep=p;
	}
	return dau;
}
nut *fifo(nut *dau)
{
	nut *tam,*p;
	int i,n;
	dau=NULL;
	printf ("Nhap so luong sinh vien cua danh sach: ");
	scanf("%d",&n);
	fflush(stdin);
	for (i=1;i<=n;i++)
	{
		p=new nut;
		printf (" Nhap ma sinh vien thu %d: ",i);
		scanf("%d", &p->sv.maSV);
		fflush(stdin);
		printf (" Nhap ho va ten sinh vien thu %d: ",i);
		gets(p->sv.tenSV);
		printf (" Nhap lop sinh vien thu %d: ",i);
		gets(p->sv.lop);
		printf (" Nhap diem cuoi ky sinh vien thu %d: ",i);
		scanf("%f",&p->sv.dck);
		fflush(stdin);
		printf (" Nhap hanh kiem sinh vien thu %d: ",i);
		gets(p->sv.hanhkiem);
		p->tiep=NULL;
		if(dau==NULL)
			dau=p;
		else
		{
			tam=dau;
			while(tam->tiep!=NULL)
				tam=tam->tiep;
			tam->tiep=p;
		}
	}
	return dau;
}
void in(nut *dau)
{
	if (dau==NULL)
		printf("\nDanh sach rong!\n");
	else
	{
		printf("%-10s %-25s %-10s %-10s %-15s\n", 
           "Ma SV", "Ho va Ten", "Lop", "Diem CK", "Hanh Kiem");
	    printf("-------------------------------------------------------------------------------\n");
	    while (dau != NULL)
	    {
	        printf("%-10d %-25s %-10s %-10.2f %-15s\n", 
	               dau->sv.maSV, dau->sv.tenSV, dau->sv.lop, dau->sv.dck, dau->sv.hanhkiem);
	        dau = dau->tiep;
    	}
	}
}
nut *tim(nut *dau)
{
	nut *tam;				
	tam=dau;
	while(tam!=NULL)
	{
		if(strcmp(tam->sv.lop,"23T3")==0)
			return tam;
		tam=tam->tiep;	
	}
	return NULL;
}

void hs23T3(nut *dau)
{
	if(tim(dau)==NULL)
		printf ("\nKhong co sinh vien nao thuoc lop 23T3!\n");
	else
	{
		printf("\nDanh sach sinh vien thuoc lop 23T3: \n");
		printf("%-10s %-25s %-10s %-10s %-15s\n", 
        "Ma SV", "Ho va Ten", "Lop", "Diem CK", "Hanh Kiem");
	    printf("-------------------------------------------------------------------------------\n");
	    while (dau != NULL)
	    {
	    	if(strcmp(dau->sv.lop,"23T3")==0)
		        printf("%-10d %-25s %-10s %-10.2f %-15s\n", 
		               dau->sv.maSV, dau->sv.tenSV, dau->sv.lop, dau->sv.dck, dau->sv.hanhkiem);
	    	dau = dau->tiep;
	    }
	}
}
nut *timhky(nut *dau)
{
	nut *tam;				
	tam=dau;
	while(tam!=NULL)
	{
		if(strcmp(tam->sv.hanhkiem,"yeu")==0)
			return tam;
		tam=tam->tiep;	
	}
	return NULL;
}
void hshky(nut *dau)
{
	if(timhky(dau)==NULL)
		printf ("\nKhong co sinh vien nao hanh kiem yeu!\n");
	else
	{
		printf("\nDanh sach sinh vien hanh kiem yeu: \n");
		printf("%-10s %-25s %-10s %-10s %-15s\n", 
        "Ma SV", "Ho va Ten", "Lop", "Diem CK", "Hanh Kiem");
	    printf("-------------------------------------------------------------------------------\n");
	    while (dau != NULL)
	    {
	    	if(strcmp(dau->sv.hanhkiem,"yeu")==0)
		        printf("%-10d %-25s %-10s %-10.2f %-15s\n", 
		               dau->sv.maSV, dau->sv.tenSV, dau->sv.lop, dau->sv.dck, dau->sv.hanhkiem);
	    	dau = dau->tiep;
	    }
	}
}
nut *sapxep(nut *dau)
{
    if (dau == NULL || dau->tiep == NULL) 
        return dau;
    nut *i, *j;
    sinhvien tam; 
    for (i = dau; i != NULL; i = i->tiep)
    {
        for (j = i->tiep; j != NULL; j = j->tiep)
        {
            if (i->sv.dck > j->sv.dck)
            {
                tam = i->sv;
                i->sv = j->sv;
                j->sv = tam;
            }
        }
    }
    return dau;
}
nut *xoaDau(nut *dau)
{
	nut *tam;
	if (dau==NULL)
		return NULL;
	else
	{
		tam=dau;
		dau=dau->tiep;
		tam->tiep=NULL;
	}
	return dau;
}
nut *xoa(nut *dau)
{
	nut *tam;
	while(dau!=NULL)
	{
		tam=dau;
		dau=dau->tiep;
		tam->tiep=NULL;
	}
	return dau;
}
nut* saoChepDanhSach(nut* dau) 
{
    if (dau == NULL) 
		return NULL;
    nut *dauMoi,*cuoiMoi ,*tam;
	dauMoi=NULL;
	cuoiMoi=NULL;
    while (dau != NULL) 
	{
        tam = new nut;
        tam->sv = dau->sv; 
        tam->tiep = NULL;
        if (dauMoi == NULL) 
		{
            dauMoi = tam;
            cuoiMoi = tam;
        } 
		else 
		{
            cuoiMoi->tiep = tam;
            cuoiMoi = tam;
        }
        dau = dau->tiep;
    }
    return dauMoi;
}

main()
{
	nut *dau,*tam;
	int c, choice;
    c=1;
	while(c!=0)
	{
		printf("===============================\n");
		printf("1. Nhap danh sach \n");
		printf("2. Hien thi danh sach duoi dang cot\n");
		printf("3. Hien thi danh sach sinh vien thuoc lop 23T3\n");
		printf("4. Sap xep danh sach sinh vien theo diem cuoi ky tang dan\n");
		printf("5. Xoa sinh vien dau khoi danh sach\n");
		printf("6. Hien thi danh sach sinh vien co hanh kiem yeu\n");
		printf("7. Xoa toan bo danh sach\n");
		printf ("0. Thoat chuong trinh\n");
		printf("Ban muon lam gi?: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				dau = fifo(dau);
				break;
			case 2:
				in(dau);
				break;
			case 3:
				hs23T3(dau);
				break;
			case 4:
				if (dau == NULL) 
        			printf("\nDanh sach rong, khong the sap xep!\n");
				else
				{
					tam=saoChepDanhSach(dau);
					tam=sapxep(tam);
					printf("\nDanh sach sinh vien sau khi sap xep: \n");
					in(tam);
				}
				break;
			case 5:
				dau=xoaDau(dau);
				printf("\nDanh sach sau khi xoa sinh vien dau: \n");
				in(dau);
				break;
			case 6:
				hshky(dau);
				break;
			case 7:
				dau=xoa(dau);
				in(dau);
				break;
			case 0:
				printf("Thoat chuong trinh thanh cong");
				c=0;
				break;
			default	:
				printf("Lua chon khong hop le");
				break;
		}
	}	
}

