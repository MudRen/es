#include "../dony.h"

inherit OBJECT;

void create()
{
        set_name("dog blunt","�򹷰�");
        add( "id" , ({ "dog blunt" }) );
        set_short( "�򹷰�");
        set_long(@C_LONG
����һ��Ե���͵Ĵ򹷰�,��������ĵ�λ��
C_LONG  );      
        set("unit","��");
        set("weight",1);
        set("no_sale",1);
        set("value", ({1, "silver"}) );
}
