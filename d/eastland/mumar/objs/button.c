#include <mudlib.h>
inherit OBJECT;
 
void create()
{
        set_name( "golden button", "�����" );
        add( "id", ({ "button" }) );
        set_short(  "�����" );
        set_long( @C_LONG
����һ�Ŵ����ƵĿ��ӣ��������һ�������
C_LONG
                );
                set("unit","��");
                set("weight", 5);
                set("value",({1, "silver"}) );
        set("no_sale", 1 );
}
