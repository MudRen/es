#include <mudlib.h>

inherit CONTAINER;

void create()
{
        ::create();
        set_name("bag", "���޴�");
        set_short("���޴�");
        set_c_open_long(@LONG
�������������˰��õĴ��ӣ�����װС����������㡣        
LONG
        );
        set( "weight", 15);
        set( "weight_apply", 55 );
        set( "max_load", 210);
        set( "value", ({ 20 , "silver" }));
        set( "prevent_insert",1 );
        set( "prevent_put_money", 1);
}
