#include <mudlib.h>

inherit OBJECT;

void create()
{
    set_name("stone of snake's eye","����֮ʯ");
    add("id",({"stone"}) );
    set_short("����֮ʯ");
    set_long(
@C_LONG
����˵����һ��ʯͷ������˵��������һ���ߵ��۾�������ʱ��
��˸��һ�����������⣬������ʲ����������á�����
C_LONG
            );
    set("unit","��");
    set("weight",25); 
    set("value", ({ 200, "silver" }));
    set( "no_sale",1); 
}    
