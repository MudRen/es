#include <mudlib.h>

inherit HERB;

void create()
{
	herb::create();
#include <compress_obj.h>
	set_name( "spicy plaster", "���������" );
	add( "id", ({ "plaster" }) );
	set_short( "���������" );
	set_long(@C_LONG
����һ��������������ҩ����������ࡹ�������˳���һ���ֲ��Ժ���ɽ
��ϡ��ҩ�ݰ��ƶ��ɣ������(apply)���˴����лָ���Ч��
C_LONG
	);
	set( "unit", "��" );
	set( "heal_apply", 7 );
	set( "duration", 30 );
        set( "weight", 15 );
	set( "value", ({ 25, "gold" }) );
}
