#include <mudlib.h>

inherit CONTAINER;

void create()
{
	::create();
	set_name( "basket", "����" );
	set_short( "����" );
	set_c_open_long(@C_LONG
���ǽ�����������������--���� ��Ʒ�����������ӱ������൱���ɣ�
����ʮ������, ����Ӧ����װ���ٶ���, �ǽ���ͳ�Я��װ��Ʒ�Ķ�����
C_LONG
 	);
	set( "weight", 15 );
    set( "weight_apply", 60);
	set( "max_load", 300);
	set( "value", ({ 413, "silver" }) );
    set( "prevent_insert",1);
}
