#include <mudlib.h>

inherit MONSTER ;

void create()
{
        ::create();
        set_level(1);
        set_name("rat","����");
        add( "id", ({ "rat" }) );
        set_short("����");
        set_long("����һֻ������С������\n");
        set("unit", "ֻ");
        set_perm_stat("dex", 3);
        set_perm_stat("int", 2);
        set_perm_stat("kar", 2);
        set_c_verbs( ({ "%s������%sһҧ", "%s������צ��ץ%s" }) );
        set_c_limbs( ({ "ͷ��", "����", "ǰצ", "����", "β��" }) );
}
