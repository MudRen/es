#include "../dony.h"

inherit OBJECT;

void create()
{
        set_name("password","����");
        add( "id" , ({ "password" }) );
        set_short( "����");
        set_long(@C_LONG
����ؤ����������͡�
C_LONG  );      
        set("unit","��");
        set("weight",5);
        set("no_sale",1);
        set("value", ({1, "silver"}) );
}
