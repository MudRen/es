#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("red coat","������");
        add("id",({"cloth","red"}) );
        set_short("������");
	set_long(@AA
һ���������ѣ�û��ʲ���ر�ĵط��������ť�����ѻ��Ļ����ĵ��ˣ�
��Ⱦ���˲��ٵľ��գ�����ÿ���Ͼƹ�����ʱ�򣬾ͻ��������·�ĬĬ
�ص��¼�����ˮ�����������һ�����µļ�֤��
AA
	);
	set( "unit", "��" );
	set( "weight", 150 );
	set( "type", "body" );
        set("material","cloth");
	set( "armor_class", 20 );
	set( "defense_bonus", 5 );
	set( "value", ({ 250, "gold" }) );
}
