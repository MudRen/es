#include <mudlib.h>

inherit ARMOR;

void create()
{
    set_name( "purple kernel", "�Ͼ���" );
    add( "id", ({ "kernel", }) );
    set_short( "�Ͼ���" );
    set_long(@LONG 
    һ�����صľ�ʯ��ɢ��������������ɫ��â�����������ϽӴ��ĵط�����һ��
ԴԴ��������������֪����ʲ���������á�     
LONG      );
    set( "unit", "��" );
    set( "type", "kernel" );
    set( "material", "element" );
    set( "defense_bonus", 5 );
    set( "weight", 60 );
    set( "value", ({ 3, "silver" }) );
}
