#include "../dony.h"

inherit OBJECT;

void create()
{
        set_name("sun pill","����������");
        add( "id" , ({ "sun pill"}) );
        set_short( "����������");
        set_long(@C_LONG
����һ�ų��ɫ��ҩ��,���������¡�
C_LONG  );      
        set("unit","��");
        set("weight",1);
        set("no_sale",1);
}
