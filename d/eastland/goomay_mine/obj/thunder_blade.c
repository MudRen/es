#include "../zeus.h"

inherit WEAPON;

void create()
{
	set_name("thunder blade", "������");
	add ("id",({ "blade"}) );
	set_short("������");
	set_long(@C_LONG
��ѵ����Ǵ�˵�У�ʯ�ҳ�������߽�ʱ��ʯ�Һú��������ʽ������
�ڵ�����Ϊ����ϡ���ĺ��������������޼᲻�ݣ��ǰ��ѵõĺõ���
C_LONG
	);
	
	set( "unit", "��" );
	set_c_verbs( ({ "��%sʹ������ʯ���쾪��������%s", 
	                "��%sʹ�������Ƹ����ۣ���ն��%s",
	                "��%sʹ�������׶����£�������%s",
	                "��%sʹ�������������֣���ֱ��%s",}) );
 	set( "weapon_class", 33 );
	set( "type", "longblade" );
	set( "min_damage", 23 );
	set( "max_damage", 38 );
	set( "weight", 250 );
	set( "value", ({ 2100, "silver" }) );
}