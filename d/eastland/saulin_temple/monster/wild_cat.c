
#include <mudlib.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level(3);
        set_name( "wild cat", "Ұè" );
        add( "id", ({ "cat" }) );
        set_short( "Ұè" );
	set("unit","ֻ");
        set_long(
	"һֻȫ���ë�Ĵ�è�������������ף�����һֻСʨ�ӡ�\n"
        );
        set_c_limbs( ({ "����", "ǰ��", "ͷ��", "β��", "����" }) );
        set_c_verbs( ({ "%s������%sһҧ", "%s������צ��ץ%s" }) );
        set_skill( "dodge", 40 );
	set_natural_armor( 15, 6 );
        set_natural_weapon( 4, 3, 6 );
        set_perm_stat( "str", 7 );
	set_perm_stat( "dex",9);
#include <replace_mob.h>
}
