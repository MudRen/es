#include <mudlib.h>
#include <conditions.h>
#include "/u/s/smore/hawk.h"
inherit MONSTER;

void create()
{
        ::create();
        set_level(19);
        set_name( "hawkman elder", "���˳���" );
        add ("id", ({ "hawkman", "elder" }) );
        set_short( "hawkman elder","���˳���");
        set("unit","λ");
        set("alignment",1500);
        set("class","adventurer");
        set_long(@LONG
��Ϊ������ĳ��ϣ����˳�����Ҳ��һ��������ս��սʿ����������������
�䶷������ѡ���������䲻һ�����ǣ����˳���ͬʱҲ��ͨĳЩ����������
�����ս�����飬ѧ����һЩ�����ս�����ɣ�������ս����ſ���˵����
��һ�����Ĵ���֮һ��������ķḻս�����������������ʹ����������
���н������з�����
LONG
        );
        set_perm_stat("str", 24);
        set_perm_stat("int", 30);
        set_perm_stat("dex", 21);
        set_natural_weapon( 45, 20, 30 );
        set_natural_armor( 45, 30 );
        set ("gender", "male");
        set ("race", "hawkman");
        set("tactic_func","sp_tactic");
        set("aiming_loc","weakest");
        set("max_hp",1400);
        set("hit_points",1400);
        set("special_defense",
                (["all":60,"monk":20,"scholar":20,"none":40,"electric":90]));
        set("aim_difficulty",
                (["critical":100,"weakest":30,"vascular":10,"ganglion":50 ])) ;
        set_skill( "whip",100 );
        set_skill( "parry",100 );
        set_skill( "dodge",70 );
        set_skill( "block",40 );
        set_skill( "anatomlogy",80);
        wield_weapon("/u/s/smore/weapon/whip1.c");
        equip_armor(ARMOR"shield2.c");
        equip_armor(ARMOR"god_1.c");
//	equip_armor(ARMOR"platemail.c");
        equip_armor(ARMOR"glove1.c");
//	equip_armor(ARMOR"helmet1.c");
//	equip_armor(ARMOR"armbands1.c");
        equip_armor(ARMOR"boots1.c");

}

void report(object holder, object victim )
{
   seteuid(getuid());
   tell_object( victim,
   sprintf("( ��%s )\n","/adm/daemons/statsd"->status_string(victim)));
}

void init()
{
        add_action("do_report","report");
}

int sp_tactic()
{
        object magics,caster;
        int dam,choice,kar,con,pie,dex,str,aa;
        choice = random(5);
        switch(choice)
        {
        case 0: return 0;

                break;
        case 1:
                if ( !(magics=query_attacker())
                        || (random(20)>random(5)) ) return 0;
                tell_room(environment(),
                        "���˳��ϴӿ����³�һ�ź�������������ס��\n"
                        "....�Ⱥ���ɢȥ���㷢�����϶��˲��ٺ�ɫ�ߵ�....\n",
                this_object() );
                con = magics->query_perm_stat("con") ;
                pie = magics->query_perm_stat("pie") ;
                dam = con * 3 - pie * 2  + random(20);
                magics->receive_special_damage("poison",dam);
                (CONDITION_PREFIX + "simple_poison")->apply_effect( magics,
15, 3 );
                return 1;
                break;
        case 2:
                if ( !(magics=query_attacker()) || (random(10)>2)) return 0;
                dex = magics->query_perm_stat("dex") ;
                if ( random(dex) > 17)
                {
                        tell_object(magics,
                                 "���˳�����������������ȵĹ�â��������������"
                                +"�ݵ����Ա�һ��....\nһ��Ư������շ�����㿪"
                                +"����εĹ�����\n\n" );
                        tell_room(environment(),
                                 (string)magics->query("c_name")
                                +"һ��Ư����ת��������շ����㿪�����˳���"
                                +"���зų���������ɫ��â��\n\n",this_object() );
                        return 1;
                }
                tell_room(environment(),
                        "���˳��ϵ�˫�����������⣬�յ���ȫ���ȡ�\n",
                               this_object() );
                tell_object(this_player(),
"���˳�����������������ȵĺ�⣬�����ȫ��ѪҺ�ƺ���Ҫ�����ˡ�\n"
                );
                dam = 30 + random(10);
                magics->receive_special_damage("energy",dam);
                report(magics,magics);
                return 1;
                break;
        case 3:
                if ( !(magics=query_attacker()) || (random(10)>2))
                        return 0;
                aa = (int)this_player()->query_temp("be_hang");
                if (aa) return 0;
                str = magics->query_perm_stat("str") ;
                if (random(str) > 17) return 0;
                tell_room(environment(),set_color(
"���˳��Ϻ�Ȼ�����еĳ��޽����Ľ��ڵ��˵Ĳ����ϡ�\n","HIR"),
                this_object() );
                dam = 15 + random(10);
                magics->receive_damage(dam);
                magics->block_attack(6);
                magics->set_temp("msg_stop_attack",
                        "( �㱻���޽�������ס��ʧȥһ���ж��Ļ��� )\n");
                magics->set_temp("be_hang",1);
                call_out("over_hang",10,magics);
                return 1;
                break;
        case 4:
                caster = present("elder");
                aa = (int)caster->query_temp("no_way_out");
                if (random(10) > 4) return 0;
                if (aa) return 0;
                tell_room(environment(),set_color(
"���˳��Ͽ�Хһ����˫��Ķ������ܾ���ǧ��ѩ������ֲ��嶫��������\n","HIB")
                ,this_object() );
                caster->set_temp("no_way_out",1);
                call_out("let_go",10,magics);
                return 1;
                break;
                }
        return 1;
}

int over_hang()
{
        object magics;
        magics = query_attacker();
        magics -> set_temp("be_hang",0);
        return 0;
}

int let_go()
{
        object caster;
        tell_room(environment(),@LONG

��ѩ���ֹͣ�����ֿ��õ����ܵĻ����ˡ�

LONG
                ,this_object() );

        caster = present("elder");
        caster -> set_temp("no_way_out",0);
        return 1;
}

void die()
{
        object killer;
        killer = query("last_attacker");
        killer->set_temp("smore_armor/elder",1);
die(1);
}

int do_report()
{
        if (this_player()->query_temp("smore_box") == 5)
        {
                tell_object(this_player(),@LONG
����˵�����Ѿ�����˵���ˣ����Ǵ�Ҷ��ܸ�л�㡣
LONG
                );
        }

        if (present("s_potion",this_object() ) &&
                this_player()->query_temp("smore_box") == 4)
        {
                tell_object(this_player(),@LONG
���Ͻӹ����ҩƿ����ϸ�Ŀ�����ã�Ȼ��̾��һ����������˵��:

лл������������������!!��������ͻ��ɰ������ʵ����Ӯ����ά�ֻ࣬��
�����Ľ��������ˣ���Ҳ����˵ʲ�ᡣ��Щ������������춰����������֮�£�
���Ǹ�ŭ�����ԣ��ҿ���������һλ�����嵨����ʿ������˵���֮��! ̫���ˣ�
�������ٿ��������ᣬ�Ҵ�������ļ���ߣ����������޷��������������ˣ�

����ת��ͷȥ��������Ļ����Ը��˼��仰���������ͷ����������ȥ�ˡ�

�������˳��ϴ����㣬���������صص���������������Ľ��ء�

LONG
                );
                this_player()->set_temp("block_command",1);
                call_out("meeting_a",5,this_player() );
        }
        else if (!present("s_potion",this_object()) &&
                this_player()->query_temp("smore_box") == 4)
        {
                tell_object(this_player(),"����˵����Ŷ����ҩˮ���İ�����\n\n" );
                return 1;
        }
        else if (this_player()->query_temp("smore_box") != 4)
                return 0;

        return 1;
}

void meeting_a()
{
    tell_object(this_player(),@LONG

�㷢���Լ��߽���һ��ǳ����ϵĴ��������ܵ�ǽ������é������������һȺ
Ⱥ�����˽�������Ъ������һ����̸�۵�������

���˳����������..." ����! ���� "!

LONG
);
    call_out("meeting_0",5,this_player() );
}

void meeting_0()
{
    tell_object(this_player(),@LONG

���ܶ�����������.....

���˳��ϻ����Ľ��������ֵ�ҩƿչʾ����ҿ���˵" ����ǵ��갢������͵
�õĽ�ҩ�����������ҩ��Ŵ����ά��! ���죬���Ǿ���Ҫ��ά��һ������
��! ������! �㻹��ʲ�Ự��˵!"

LONG
);
    call_out("meeting_1",10,this_player());
}

void meeting_1()
{
    tell_object(this_player(),@LONG
���������ϻ���һĨ�ľ��ȣ����漴���ţ������ЦЦ������˵��:
" ��! ����һ��С����ƿ�ӣ���Ҫ����������? ����Ϊ���ǳ����Ҿ�������! "
������ָ���� "��! ����˭��? �������������Ҳ�����ǵĽ��ض������? ����!"

������˵��Ͱν��������Ͽ���!

����ǧ��һ��֮�ʣ����˳���˫��һ�죬����һ���ͰѰ�����Ľ�������!
���˳���Ŀ�⾼��������������˵��:
" ������! ��������Ī�����������飬ɱ�������? ������һ�в������� !"

LONG
);
    call_out("meeting_2",8,this_player());
}

void meeting_2()
{
    tell_object(this_player(),@LONG
����˿Ҳ����˵:
" �������Һ�ϣ��������׵ģ�ֻ����Щ������ʼ���޷��˽�����������ά��
�ģ�Ҳ��������������Ե���ҵ����������壬���ڳ�������ƿ��ҩ������
�ո�����Ҳ��̵ķ������������׶඼������? ��Щ�ɵ�δ��̫�������˰�? "

����˿ת������������ "���ˣ����ѣ��㻹֪��ʲ��������֤����? "

LONG
);
    call_out("meeting_3",5,this_player());

}

void meeting_3()
{
    tell_object(this_player(),@LONG
��վ�˳���������ȫ���������ǰ����˵�� :
" ��λ�װ���������������! ��������߹�--�׶࣬���������������˵������ϴ�
ͨ�ã��ð������������ǿ������������ҩ������ά�࣬Ȼ����ҩȴ��������
����Ľ�ҩ����Ϊ�����������˵ĳ��Ӳ�����ɲ�������Ҳ����˵....

    ���������������������֡��ڡ������͡��������ᡫ��!!!  "

�㻰һ˵�꣬�����ǿ�ʼ�����������׷׵��ò�м��������������!

LONG
);
    call_out("meeting_4",10,this_player());
}

void meeting_4()
{
    	tell_object(this_player(),@LONG

�������۾������ʺ�ɱ�������" ˵��! ˵��! ��Ҫ������!!"

���˳���������������һ�ӣ�������������˳�ƾ���������!
���˳��Ͽ��˿�������˵:
" ���ڣ����Ǹ���֤���Ļ�����! "

���˳��ϰ���һ�ѱ����������ĳ�����������������ֵĸо���˫�ž���
���˵���..... �����ģ�����������Ҳ�����ɵ��˿��У���������ĸ���!
ֻ�����������Ǽ��������вҽУ�ԭ������ķɲ����ˣ�����������յĿ���
���ӣ��ڳ�ȴû���κ�һλ����Ը����ȥ��������ɼ�������������˰�!

�����������д���һ���������Ĳҽ��������Բ��𡫡����Ҵ��ˡ�����������
�ɵ���Ĳ��̣�˵���������ˣ��Ź����ɣ����ǻ���Ҫ��������������������
�������ء���
LONG
        );
    call_out("meeting_5",5,this_player() );
}

void meeting_5()
{
        tell_object(this_player(),@LONG

���˳�����һ���ɣ����ͷ��˵���������´α�����֮ǰ�������ð�������
�ݴ�����ְ��ɣ��׶��������Ѿ��ܵ���Ӧ�еĴ������Ǿ͹��ˡ���

������һ�ӣ�һ����꽫���ܴ��Ϩ�����±��һ��յ�����һϢ�İ�����
���������ɹ�ȥ�Ѱ��������������س��ڡ�

���˳��ϴ�����ص��˴��䡣... ....

LONG
        );

        this_player()->move_player("/u/s/smore/hawk/room3-2","SNEAK");
        this_player()->set_temp("block_command",0);
        this_player()->set_temp("smore_box",5);
	call_out("ending",5,this_player() );
}

void ending()
{
	tell_object(this_player(),@LONG
���϶���˵����л��Ϊ������������࣬����˵���ҵ���ά��ķ�Ĺ������
�����ٵ�ά���Ĺǰ������������ԩ���Ѿ�����ϴˢ�ˡ�
LONG
	);
}

