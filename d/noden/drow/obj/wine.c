#include <mudlib.h>

inherit POTION;

void create()
{
        potion::create();
        set_name( "wine","����");
        add( "id", ({ "wine" }) );
        set_short( "����");
        set_long(
@C_LONG
����һ�����ϴ峤�����Ƶ����ƣ��������й�Ũ����ҩζ������
��������в�ʹ���ˣ����в��ٵ���Ч�ɡ�
C_LONG
        );
// so high ???
// set_healing(250);
   set_healing(100);
        set( "no_sale", 1 );
        set( "unit", "��");
        set( "weight", 40 );
        set( "value", ({ 700, "silver" }) );
        set( "medication",10 );
        set( "effect_critical",10 );
}
