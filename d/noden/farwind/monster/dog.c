
#include <mudlib.h>

inherit MONSTER ;

void create()
{
        ::create();
        set_level(1);
        set_name("dog" ,"��");
        add( "id", ({ "dog" }) );
        set_short( "Ұ��");
        set_long(
                "����һֻҰ��, ����ò�Ҫ��㿿������\n"
        );
   set( "race", "beast" );
        set("unit", "ֻ");
        set_perm_stat("str", 3);
        set_perm_stat("con", 2);
        set_perm_stat("dex", 3);
        set_c_verbs( ({ "%s������%sһҧ", "%s������צ��ץ%s" }) );
        set_c_limbs( ({ "����", "ǰ��", "ͷ��", "β��", "����" }) );
}
