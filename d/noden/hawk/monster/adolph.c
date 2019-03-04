inherit MONSTER;
int will_die = 0;
#include "../hawk.h"
void create()
{
        ::create();
        set_level(19);
        set_name( "Hawkman Leader Adolph", "�������� ������" );
        add ("id", ({ "adolph","leader","hawkman"}) );
        set_short( "�������� ������" );
        set_long(@C_LONG
����������������������䣬������Ȳ��ϸ��ά��(Vito)����Ҳ���൱
���ס��������������ϵ��װ���������֮�������ഫ����ʥװ����ֻ������
����������ʸ�ӵ������ӵ�������֮����ʥ֮���ı����������˵�ǲ���֮
������ƽ���ķ���������ǲ����ܵģ�ֻҪ��������û�п־�֮�ģ���ʥ֮
���ı�������û�������ġ�
C_LONG
        );
        set( "race", "hawkman" );
        set( "gender", "male" );
	set( "alignment", -2000);
        set_perm_stat( "str", 30 );
        set_perm_stat( "dex", 18 );
        set_perm_stat( "kar", 10 );
        set_perm_stat( "pie", 17 );
        wield_weapon(WEAPON"skysword.c");
        equip_armor(ARMOR"samulet.c");
        //equip_armor(ARMOR"shelmet.c");
        equip_armor(ARMOR"splate.c");
        //equip_armor(ARMOR"slegs.c");
        equip_armor(ARMOR"sshield.c");
        //equip_armor(ARMOR"sfoots.c");
        //equip_armor(ARMOR"sarms.c");
//	 equip_armor(ARMOR"sgloves.c");
        set("special_defense",
                (["all":50, "cold":70, "fire":65, "electric":0,
                        "evil":50, "none":70, ]));
        set("max_hp",900);
        set("hit_points",800);
        set( "inquiry", ([
                "vito" : "@@ask_vito",
                "juraken" : "@@ask_juraken",
                        ]) );
        set_skill( "dodge", 60 );
        set_skill( "parry", 80 );
        set_skill( "block", 80 );
	set_skill( "longblade", 100);
        set( "aim_difficulty",([ "weakest":50,"critical":100,"vascular":90,"ganglion":40
]) );
	set_natural_armor(40,20);
	set_natural_weapon( 15, 15, 36);
        set( "tactic_func","my_tactic");
        set( "wealth/silver", 800);
}

void init()
{
        object ob;
        npc::init();
        if( !(ob= this_player()) || !userp(ob) ) return;
        if( ob->query_temp("kill_me") )
        {
                kill_ob( ob );
        }
        if( ob->query_temp("control_flesh") == 2 )
        {
                command("scream");
                will_die = 1;
        }
}

int ask_vito()
{
        tell_object(this_player(),@LONG
�������Ц�����������е��������������Ǹ��������˸���۸�������ã�
����ֵ����˰ɣ���
����ð���������е����񲣬��֪��Ϊʲ������Լ����׸��Ҳ���Թ�ߣ���
��ҡҡͷ��
LONG
        );
        return 1;
}

int ask_juraken()
{
        tell_object(this_player(),@LONG
������˵�����Ǻǣ��������ҵĺ����ѣ������Һܶ��æ���ϴ���ķķ���
����Ҳ�ǿ������ǲ�Ӯ�ġ����˱�Թ˵��Ϊ���Ĺ�ϵ���Ǹ���ķķ��Ҳ���˵���
��������ɶ��ϵ�أ������������岻�ݴǵģ�������
LONG
        );
        return 1;
}

void report(object holder, object victim )
{
   seteuid(getuid());
   tell_object( victim,
   sprintf("( ��%s )\n","/adm/daemons/statsd"->status_string(victim)));
}

int my_tactic()
{
        object victim;
        if (!victim = query_attacker()) return 0;
	if (random(100) > 13 ) return 0;
        tell_room(environment(victim),
"\n\n�������������Ȼ�ּ�ۼ���һ���貵Ĺ���ֱ����"+
(string)victim->query("c_name")+"��ͷ�ϡ�\n\n",victim
        );

        tell_object(victim,set_color(sprintf(
"��������һ���������ҵ�Ǭ�������ⵯ����\nͻȻ���еĹ�������ֱ"+
"���˹�����һȦ譲ӵĹ⻷�����������ԣ������Ĺ���\n�����۾�����"+
"��������......���Ȼ�����Լ�˫�۶�������������\n"),"HIY")
 );
        victim->receive_special_damage( "energy", random(15)+40 );
        report(victim,victim);
        victim->set("blind",1);
        return 1;
}

int die()
{
        if (will_die != 1)
        {
                object *ob,killer;
                int i;
                set( "exp_reward",300 );
                ob = all_inventory(this_object());

                for( i=0; i<sizeof(ob); i++ )
                        ob[i]->remove();


                tell_room( environment(this_object()),@LONG

����ػ����·ų�һ����⣬���������ϵ�����ȫ�������ˡ�

�������Ц�������۹����������ǲ����ġ����������޵еġ�������������ЩϺ��
з����Ҫ�ٶ���������....��

������װ��һһ����֮���ֳ������˳��˹�ȥ��
LONG
                ,this_object() );
                killer = query("last_attacker");
                killer->set_temp("kill_me",1);
		set( "alt_corpse","/u/s/smore/mob/adolph.c");
                ::die(1);
                return 1;
        }

        tell_room( environment(this_object() ),@LONG

������̾һ�������벻����������ϻ����˿��Ի����ҡ���������
LONG
        ,this_object() );
        ::die(1);
        return 1;
}
