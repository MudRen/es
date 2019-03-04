#include <mudlib.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level(12);
        set_name( "hawkman elder", "���˳���" );
        add ("id", ({ "hawkman", "elder" }) );
        set_short( "hawkman elder","���˳���");
        set("unit","λ");
        set("alignment",500);
        set_long(@LONG
  ��Ϊ������ĳ��ϣ����˳��Ϻ����������䶷������ѡ���������䲻һ����
�ǣ����ɶ����ս�����飬ѧ����һЩ�����ս�����ɡ�������Ȼ������������
��һ��ǿ׳��սʿ���������Ǻ��۸��ġ����ַ�������������������۵ı��ӣ�
��֪�Ǹ�ɶ�õģ�����Ӧ�ò��ǣӣͣ�����̫���š�
    ����������ƺ��粨���ϣ����˳��ϲ���Ҳ��üͷ������������������ڷ�
��Щʲ�ᣬ˵��������԰���(help)��ม�
LONG
        );
        set_perm_stat("str", 11);
        set_perm_stat("dex", 7);
        set_natural_weapon( 15, 10, 16 );
        set_natural_armor( 25, 10 );
        set ("gender", "male");
        set ("race", "hawkman");
        set("tactic_func","sp_tactic");
        set("max_hp",250);
        set("hit_points",250);
        set("special_defense",(["all":20,"none":10,"electric":40]));
        set("aim_difficulty",(["critical":10,"weakest":10,
                               "vascular":10,"ganglion":10 ])) ;
        set_skill( "parry",30 );
        set_skill( "dodge",50 );
        set_skill( "whip",80);
        set( "inquiry", ([
                "help" : "@@ask_help",
                        ]) );
}

void init()
{
        add_action("do_report","report");
}

int do_report()
{
        if (this_player()->query_temp("smore_box") == 5)
        {
                tell_object(this_player(),@LONG
����˵�����Ѿ�����˵���ˣ����Ǵ�Ҷ��ܸ�л�㡣
LONG
                );
	return 1;
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

���˳����������..." ����! ���� !"

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

����˿ת������������ "���ˣ����ѣ��㻹֪��Щʲ��������֤����? "

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

int ask_help()
{
        tell_object(this_player(),@LONG

���˳���̾�˿�����˵��
    ����������겻������ս��������˲��أ������������治�Ǹ��õ���
�䣬����ƫƫ����Ӯ���䶷��ᡣ��ϣ��ά���ܹ����������쵼�����壬��Ȼ��
���������Ҫ������������һ���ˡ�ǰһ������˵ά��������л�������ȴ����
����ɭ���������ҵ����������Ķ�����˵��������̽����ά������䡣
LONG
        );
        return 1;
}

int sp_tactic()
{
        object magics;
        int dam;
        if ( !(magics=query_attacker()) || (random(12)>3)) return 0;
        magics->set_temp("kill_elder",1);
        tell_room(environment(),
        "\n\n���˳��Ϻ�Ȼ�����еĳ��޽����Ľ��ڶ��ֵĲ����ϡ�\n",
        this_object() );
        dam = 10 + random(5);
        magics->receive_damage(dam);
        magics->block_attack(2);
        magics->set_temp("msg_stop_attack",
                "( �㱻���޽�������ס��ʧȥһ���ж��Ļ��� )\n");
        return 1;
}

void die()
{
        object *attackers, elder;
        int i;
        tell_room( environment(this_object()),
        "���˳��ϴ�����Ц�� ࡺǺ�....�㻹������ .... \n\n"
        "һ���紵�������˳��Ͼ���վ������\n"
        "���˳��ϴ�У���ʶһ����������ʵ����\n\n"
        "ֻ�����˳����ƺ�Խ��Խ�ߣ�ȫ��ļ���Ҳ�������������ٴ������ó�
�������ߴ���....\n\n"
        ,this_object() );
        elder = new("/u/s/smore/mob/elder.c");
        elder->move( environment(this_object()) );
        attackers = this_object()->query_attackers();
        for( i=0; i<sizeof(attackers); i++ )
                elder->kill_ob( attackers[i] );
        this_object()->remove();
        ::die(1);
}
