#include <mudlib.h>

inherit OBJECT;

void create()
{
        set_name("spirit ball","������");
        add( "id" , ({ "ball" }) );
        set_short( "������");
        set_long(@C_LONG
һ��ī��ɫ��Բ������һ�������顣
C_LONG  );      
        set("unit","��");
        set("weight",50);
        set("no_sale",1);
        set("spiritball",1);
        set("master","???");
        set("value", ({1, "silver"}) );
}
