#include <mudlib.h>

inherit MONSTER;

void create()
{

	::create();
	set_level(10);
	set_name( "pink girl", "�ۺ�ɫСŮ��" );
	add( "id",({ "girl" }) );
   set_short( "�ۺ�ɫСŮ��" );
	set_long(
		"�㿴��һ���ۺ�ɫ������΢���СŮ������Ӱ���������������Ǻ���\n"
           "����ʹ�㲻���������ǲ��ǹ�ꡣ�������������һЩ���Ĺ�ҵ���\n"
           "�顣\n"
	);
	set_perm_stat( "str", 6);
	set_perm_stat( "int", 16);
	set_skill( "dodge", 70);
	set_skill( "tactic", 70 );

	set( "alignment", 1000 );
	set( "tactic", "flank" );
	set( "race", "shapeshifter" );
	set( "gender", "female" );
	set_natural_armor( 30, 10 );
	set_natural_weapon( 20, 6, 8 );
	set( "wealth/gold", 5 );
   set( "inquiry", ([
            "mummy" : "�Ǹ��������ް����ļһﰡ?\n"
                      "�������������, ����������������\n",
            "torch" : "����������ֻ��Ѱ�? ��������(pull)�ͺ���...\n"
                       "����...����...�Ҳ���������������...\n",
            "skeleton" :
@LONG
��...�����ҵ�ʬ��............
���ҵ�һ��������ĹѨʱ, ��С�Ĵ���һ���пֲ�����
�ķ���; ��һգ�ۼ�, �����о綾, ʹ�಻��........
��������, ����ʹ������, ����һ�������˶�........
LONG
   ]) );

   equip_armor( "/d/noden/tomb/obj/bkernel" );
}
