#include "../story.h"

inherit SMOB"pmob";
void create()
{
	::create();
	set_level(19);
	set_name( "Blue-Face scorpio's head", "������Ы" );
	add( "id", ({ "head","scorpio" }) );
	set_short( "������Ы��ͷ��" );
	set_long(@C_LONG
����ǰ��������ֻ���;޴��ޱȣ�ȫ��������ɫ��Ы�ӡ�����ͷ������һ���˵�
��������ǰȴ��͹����ֻ�豭��С�Ĺ��ۣ�����֮����â���䣬��������������
˸������
C_LONG
        );
	set("pname","������Ы");
	set( "alignment", -1000 );
        set_perm_stat( "str", 25 );
        set_perm_stat( "dex", 30 );
        set_perm_stat( "pie", 10 );
        set_perm_stat( "int", 25 );
        set_perm_stat( "kar", 30 ); 
        set_skill("dodge",100);
        set_skill("unarmed",100);
        set("hit_points",2000);
        set("max_hp",2000);
        set_natural_armor(90,15);
        set_natural_weapon( 61,44,56 );
        set("special_defense", (["all":30,"none":25]) );
        set_c_limbs( ({ "�۾�", "����", "��ͷ", "����"}) );
        set_c_verbs( ({ 
            "%s�����Ķ�ͷ��ײ%s",
            "%s������������%sһҧ",
            "%s�������������Ķ�����%sһ�"}) );
}
