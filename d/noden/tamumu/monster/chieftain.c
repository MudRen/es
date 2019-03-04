#include <mudlib.h>
inherit MONSTER;

void create()
{
        object ob1, ob2;

        ::create();
        set_level(18);
        set_name( "sa-ba'tuka", "�����¿�" );
        add( "id", ({ "chieftain", "tamumu", "tamumu chieftain" }) );
        set_short( "��ķķ���� �����¿�" );
        set_long(@C_LONG
�����¿�����ķķ�������������������ķķ��ΰ���սʿ��������
�ǻ�Ҳ�ܸߣ��㿴�����������������ɫ�Ĵ��࣬����������ķķ��
��ǿ׳����ʿ��
C_LONG
                );
        set( "max_hp", 550 );
        set( "hit_points", 550 );
        set( "unit", "λ" );
        set( "race", "human" );
        set( "gender", "male" );
        set( "alignment", -900 );
        set( "tactic", "berserk" );
        set_perm_stat( "str", 25 );
        set_perm_stat( "dex", 23 );
        set_perm_stat( "int", 20 );
        set_perm_stat( "pie", 14 );
        set_skill( "longblade", 100 );
        set_skill( "parry", 90 );
        set_skill( "block", 100 );
        set_skill( "tactic", 100 );

        set( "wealth/gold", 60 );
        set( "natural_armor_class", 70 );
        set( "natural_defense_bonus", 25 );
        set( "inquiry", ([
                "juraken":"@@ask_juraken",
             "flesheater":"@@ask_flesh"
                        ]) );

        ob1 = new( "/d/noden/tamumu/obj/sword" );
        ob1->move( this_object() );
        wield_weapon( ob1 );

        ob2 = new( "/d/noden/tamumu/obj/chief_shield" );
        ob2->move( this_object() );
        equip_armor( ob2 );
}

int ask_juraken()
{
        tell_object( this_player(),@LONG
�����¿�������˵�����ߣ����ɶ�������������귢������ı��������ķ
ķ�������ഫ�ı��أ���Ǳ��Ҹϳ������벻���̶�û���꣬����û��ն�ݳ�
��������ͳ����ˣ������Լ�ѧ�����������̵�а�������ڵ��������Ծ�����
��򵥵�����Ӧ���ĵ��ġ������ϴ����Ǿ�������ʳ��(flesheater)һ�𹥻�
���˹ȣ���Ϊ��ʳ�޲�������������������硣�벻����ս����ҵ�ʱ��
����������ʳ�޵ı��龹Ȼʧȥ��ħ�����������ʳ�޵��Ҳ��֣���������ķ
ķսʿɱ��Ѫ����ӣ�����ǧ�������ܷ��������˻�����Ҳ����ϴε���ս
ʧ���ˣ����ǿ�ϧ��~~~
LONG
        );
        return 1;

}

int ask_flesh()
{
        object obj;
        if (this_player()->query_temp("kill_juraken") != 1)
        {
                tell_object(this_player(),@LONG
�����¿�˵��ʳ���ޣ���������ķķ�������ഫ���������ǵ�ʥ�ޣ�����
��צ�Ӻ�ǿ����������˺����������в�һ���򵥡�����������ķķ��������
���������ǵĻ�ħ�顣�����ӵ�ħ������ʹ��ʳ�޵��������ǵ�����ϴ�һ
����ս������ħ�����Ĺ������ʧȥ�˹�â�����ڱ����ħ���ֲ�����ˣ�
�������Ҫ�Ļ���ֻҪ������ɱ�����������Ҿ�������ű��顣
LONG
                );
                return 1;
        }

        if (this_player()->query_temp("kill_juraken") == 1)
        {
                tell_object(this_player(),@LONG
�����¿�˵���ţ�лл��Ϊ��ɱ�����������ϴν��õ�л������ⶫ����

�����¿��ó���һ��Ѫ��ɫ�����ӡ�
�����¿�˵��������ű��飬�ߵ�ʳ�����ԣ��૵�����"ern!-sdl"�Ϳɽ���
��ͷħ�ޡ�
LONG
                );
		obj = new( "/d/noden/hawk/obj/pearl" );
                obj -> move(this_object() );
                command("give pearl to " + this_player()->query("name") );
                call_out("part2",5,this_player() );
                return 1;
        }
        return 1;
}


int part2()
{
        tell_object(this_player(),@LONG
�����¿������㣺���ˣ���Ҫ�õ��������Ͽɲ���ม�Ҳ����˵Ҫ���������ϵ�
����ȡ�����������˼�ı���������û�����ˡ�
LONG
        );
        return 1;
}
