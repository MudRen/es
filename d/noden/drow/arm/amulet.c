#include <mudlib.h>
inherit ARMOR;

void create()
{
   set_name("copper rings", "ͭ����");
   add( "id", ({ "rings" }) );
	set_short( "ͭ����" );
        set_long(
@C_LONG
���ͭ���������Ѿ������Զ��������Ȼĥ�Ĺ������Ǻڰ������
װ��Ʒ��
C_LONG
        );
	set( "unit", "��");
        set( "type", "misc" );
	set( "material", "heavy_metal" );
	set( "defense_bonus", 2 );                       
	set( "weight", 60 );
	set( "value", ({ 200, "silver" }) );
}
