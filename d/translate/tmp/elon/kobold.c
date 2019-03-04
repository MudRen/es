#include <mudlib.h>
 
inherit MONSTER;
 
void create()
{
        ::create();
        set_level(1);
        set_name( "kobold", "kobold" );
        set_short( "kobold", "kobold" );
        set_long(
"A short humanoid creature stands in front of you. He looks at you\n"+
"as if you are invading his living space and he is not happy with\n"+
"this.\n",
"A short humanoid creature stands in front of you. He looks at you\n"+
"as if you are invading his living space and he is not happy with\n"+
"this.\n"
        );
        set( "max_hp", 30 );
        set( "hit_points", 30 );
        set( "race", "kobold" );
        set( "gender", "male" );
        set( "alignment", -200 );
        set_perm_stat("int",3);
        set_perm_stat("dex",5);
        set_skill("shortblade",random(20)+10);
        set_skill("parry",random(30)+10);
        set("wealth/silver",10);
        set_natural_armor(20,0);
        set_natural_weapon(5,1,4);
        set("weight", 300);
        set_limbs( ({"body","head","legs","hands"}) );
        set_c_limbs( ({"������ ","��ͷ ","�Ľ� ","���� "}) );
        set_verbs( ({"kick","hit","bite"}) );
        set_c_verbs( ({"%s�� %s","%s�� %s","%sҧ %sһ��"}) );
}
 
void init()
{
    ::init();
    if ((string)this_player()->query("race")=="gnome") {
        write(can_read_chinese()?
        "Kobold ���: ��������ؾ���! ��Զһ��!\n":
        "Kobold yells: Gnomes!! I hate them!\n");
        kill_ob(this_player());
    }
}
 
int catch_huntee(object who)
{
    if ((string)who->query("race")=="gnome") {
        write(can_read_chinese()?
        "Kobold �е�: ��, ��������?\n":
        "Kobold shouts: come for your death again?\n");
        return 1;
    }
    return 1;
}
 
