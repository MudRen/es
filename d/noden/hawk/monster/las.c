#include <mudlib.h>
#include "../hawk.h"
inherit MONSTER;

void create()
{
        ::create();
        set_level(19);
        set_name( "Poet Las", "����ʫ�� ��˹" );
        add ("id", ({ "las", "poet" }) );
        set_short( "����ʫ�� ��˹");
        set_long(@LONG
��˹��ħ���к���������ʫ�ˣ����Ժ�ɱ��ȴ��ϲ���˽�飬����
����������ʶΪ���ѣ�Ϊ��ҪѰ�Ҹ�ǿ�ĵ��֣����ͷ糾���͵ĸϵ���
����������Ϊ��Щ����������ð���߿������֮�š�����������ɫ�Ұ�
�޹⣬��¶��һ��������������ӣ��������ǧ��Ҫ��Ϊ������
���Ǻ��۸��ġ�
LONG
        );
        set_perm_stat("str", 30 );
        set_perm_stat("con", 25 );
        set_perm_stat("int", 30 );
        set_perm_stat("dex",15);
        set_skill( "dodge", 100 );
        set_skill( "blunt", 85 );
        set( "alignment", -1500 );
        set( "race", "daemon" );
        set( "gender", "male" );
        set( "hit_points", 900 );
        set( "max_hp", 900 );
        set( "killer", 1);
        set( "pursuing", 1);
        set( "tactic_func","my_tactic");
        set( "aim_difficulty",
        ([ "critical":80,"weakest":20,"ganglion":30,"vascular":50 ]) );
        set_natural_weapon( 20, 20, 30 );
        set_natural_armor( 25, 40 );
        set ("special_defense", ([
                "monk": 20, "scholar": 20, "all": 20 , "none" : 20]) );
        command("party form");
	wield_weapon(WEAPON"flute");
        equip_armor(ARMOR"shield1.c");
        equip_armor(ARMOR"god_2.c");
        equip_armor(ARMOR"white_suit.c");
}

int stop_attack(object player)
{
        call_out( "defend_las", 1, player);
        return 0;
}

void defend_las(object obj)
{
        int i;
        object env, *inv, atk;

        env = environment( this_object() );
        if( !env ) return;

        inv = all_inventory(env);
        atk = query_attacker();
        for( i=0; i<sizeof(inv); i++ ) {
                if( (string)inv[i]->query("name")=="Dead Spirit Knight" &&
inv[i]!=atk){
        //      && (!atk || member_array( inv[i], atk )==-1) ) {
                        tell_room( env,
                                inv[i]->query("c_name") +
"�嵽��˹��ǰ��ȫ����������˹��\n",
                                inv[i] );
                        inv[i]->force_me( "protect king" );
                        inv[i]->kill_ob(atk);
                }
        }
        return;
}

int my_tactic()
{
        int choice;
        object victim;

        if (!victim = query_attacker()) return 0;
        switch(choice=random(3) )
       {
        case 0 : return 0;
                 break;
        case 1 :
//����������
        if ( random(20) < 16) return 0;
        tell_room(environment(victim),
"\n��˹�����Ľ������õ���ߣ�����"+
(string)victim->query("c_name")+"������������ȵĵ�����������һʱ
�׵罻�ӣ���ر�ɫ���ݷ����֮����Ϊ"+(string)victim->query("c_name")+"�򿪡�\n"
,victim
        );
        tell_object(victim,@C_LONG

��˹�������õ���ߣ���Ц��Ц������������ĵ�����������
�������ˡ����ء������ء����������ˡ�������
����һ����ʱ����ر�ɫ�����������ˣ��ڰ���������������������Χס��

��о������ϵ�Ƥ�⿪ʼ����������ǣ�����ֻ�ܲ��������������������裬
���п�ʼ�������С������������û��䣬�㿴��Զ�����������ڿ��еľ���
�ڸ������֣��ڸ�Զ��ǰ���ƺ����и����������ļһ�����Ц��.......

C_LONG
    );
        victim->receive_special_damage( "evil", random(10)+30);
        return 1;
      break;
    case 2:
//����ʫƪ
        if ( random(20) < 17 ) return 0;
        tell_room(environment(victim),
"\n��˹ת�����ӣ������"+
(string)victim->query("c_name")+"���Ƶ����һ�γ���������ʫƪ��ֻ��"+
(string)victim->query("c_name")+"����¶��Ц�ݣ����Ӳ�ס��ҡ��������\n"
        );
        tell_object(victim,@C_LONG

��˹ת������������㣬�������е�ʫ������������������
        �������ԳƸ߹󳬷���
                �ر��������������ܣ�
        ���������������ӯ��
        ��������������а�����������
        ��֪��������������ޣ�
        �����������ɲ�ǣ�����֮��ҲΪ֮��������

���������˹��������ʫƪ....һ����������....���ɵ�����һ��
��ʹ....��������....
C_LONG
    );
        victim->block_attack(6);
        victim->set_temp("msg_stop_attack",
                "( �����г������⣬�޷������� )\n" );
        victim->receive_special_damage( "devine", random(25)+40);
        return 1;
        break;
        default: return 0;
        break;
     }

}

void die()
{
        object killer;
        killer = query("last_attacker");
        killer->set_temp("smore_armor/las",1);
        ::die();
        return;
}
