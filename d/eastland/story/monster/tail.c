#include "../story.h"

inherit SMOB"pmob";
void create()
{
	::create();
        set_level(19);
        set_name( "Blue-Face scorpio's tail", "������Ы" );
        add( "id", ({ "tail","scorpio" }) );
        set_short( "������Ы��β��" );
        set_long(@C_LONG
����ǰ��������ֻ���;޴��ޱȣ�ȫ��������ɫ��Ы�ӣ�����β������ǰ������
�����һ����ĩ�˵����̸��Ǵ�ĺ��ˣ�����ʱ������������ǰ�ΰ��εģ�һ����
�Ƶ����ӡ�
C_LONG
        );
	set("tail",1);
	set("pname","������Ы");
	set( "alignment", -1000 );
        set_skill("dodge",100);
        set("hit_points",2000);
        set("max_hp",2000);
        set_perm_stat( "int", 25 );
        set_perm_stat( "kar", 30 );
        set_perm_stat( "dex", 25 );
        set_perm_stat( "str", 25 );
        set_perm_stat( "pie", 25 );
        set_natural_armor(10,45);
        set_c_limbs( ({ "����", "β��"}) );
}
