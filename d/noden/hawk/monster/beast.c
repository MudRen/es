#include <mudlib.h>

inherit MONSTER;

int times,jump;

void create ()
{
        ::create();
        set_level(19);
        set_name("Shadow Beast","Ӱ��");
        add("id",({"shadow","beast","shadow beast"}) );
        set_short("Ӱ��");
        set_long(@C_LONG
̫�ŵ�ħ�ޣ����������ӵ�������������ħ��֮һ��
C_LONG
        );
        set("alignment",-100000);
        set( "gender", "male" );
        set( "race", "beast");
        set( "unit", "ֻ" );
        set_perm_stat( "dex",27);
        set_perm_stat( "int",30);
        set_perm_stat( "karma",27);
        set("max_hp",500);
        set("max_sp",3800);
        set("hit_points",500);
        set("spell_points",3800);
        set_natural_weapon(25,10,22);
        set_natural_armor(55,25);
        set( "tactic_func","my_tactic");
        set("aim_difficulty",(["critical":10, "vascular":10]) );
        set("special_defense", (["all":50,"none":30]) );
        set_skill("dodge",70);
        set( "killer", 1);
        set( "pursuing", 1);
        set("spells/heart-griping",2);
        set("spells/flare",1);
        set("spells/sleet",2);
        set("time_to_heal",10);
        set("cast_busy",2 ) ;
        set_temp("detect_invis",1) ;
        set_skill("concentrate",100);
        set_skill("target",100);
        set_skill("black-magic",100);
        set_skill("elemental",100);
        set("guild_levels/black-magic",80) ;
        set("guild_levels/elemental",80);
        set("guild_levels/guild",80);
}

int my_tactic()
{
        int i;
        object victim;
        string name;
        if ( !(victim = query_attacker()) ) return 0;
        if (random(10) < 2) return 0;
        if ((int)this_object()->query("spell_points")<1000)
                this_object()->set("spell_points",3800);

        name=(string)victim->query("name");
        i=random(3);
        switch (i)
        {
                case 0:
                        command("cast heart-griping on "+name);
                        break;
                case 1:
                        command("cast flare on "+name);
                        break;
                case 2:
                        command("cast sleet on "+name);
                        break;
                default :
                        command("say �г��:~~\n");
                        break;
        }

    return 1;
}



