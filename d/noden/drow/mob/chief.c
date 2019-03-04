#include "../iigima.h"

inherit MONSTER ;

void create ()
{

        ::create();
        set_level(9);
        set_name( "Drow village leader","�ϴ峤");
        add ("id", ({ "drow", "leader" }) );
        set_short( "Drow village leader","�ϴ峤");
        set("unit","λ");
        set_long(
@C_LONG
�������һ���ȴ��Ȼ���������ڵ�Э�������������Ǻڰ�������
�ϴ峤��������ִ�⽫һλŮ��˾������̳���룬�ƺ�������ϴ塡
���ķ���(trouble)������԰������
C_LONG
        );
        set_perm_stat("str", 12);
        set_perm_stat("dex", 11);
        set_natural_weapon(10,6,9);
        set_natural_armor(25,10);
        set( "special_defense",
                (["all":15,"fire":-10,"cold":-10,
                        "evil":30,"divine":-30,"none":5 ]) );
        set("gender", "male");
        set("wealth/copper",500);
        set("weight" , 700);
        set ("race", "drow");
        set( "inquiry", ([
                "trouble" : "Ů��˾�𣿰����������ĵٵ£�˭��ȥ��(help)���أ� \n",
                "help" : "�ٵ±�����͵�˾�ȿ����(temple)�ˣ����Ѿ��׸����ˣ�Ҫ��ξ����أ�\n",
                "temple" : "ร������ƽ�����ǲ��ܽ�ȥ����������������(valor)�Ĵ��˲��ܽ�������\n",
                "valor" : "@@ask_valor",
      "mark" : "���ʣ��㵽��Ҫ��Ҫȥ������\n",
               ]) );
        wield_weapon(OBJ"copper_blunt");
        equip_armor(ARM"bracers");
        equip_armor(ARM"ring1");
}

int ask_valor()
{
        tell_object(this_player(),@LONG
�峤˵��ࡣ���Ҳ�����Լ�����������ǰ��������Ķ�˵�����ߣ�
�����ƭ�ҡ��������ԣ��Ҿ������������ܵõ��޿�˼���Ͽɣ���ͨ����
�Ŀ��鲢�������Ļ���(mark)���ң�֤�� (certification)�������ߣ���
�ٽ�����ο�����
LONG
        );
        this_player()->set_temp("drow_certi",1);
        return 1;
}


int accept_item(object me, object item)
{
        string name;
        object ob;

        name=(string)item->query("name");
        if (!name || (name!="captain's seal"))
                return 1;

        write("�ϴ峤˵���ţ��ǻ���û����ȵȣ�������\n");
        if (!this_object()->query("scale"))
        {
                write("�ϴ峤˵����ȥ�ɣ���Ƭ���۵������ף����Ŷ�����а����ġ�\n");
                ob=new(OBJ"scale");
                ob->move(this_player());
                set("scale",1);
        }
        else
                write("�ϴ峤������˵�������ϧ������Ҳ���һ����ˣ�����Ƿ�ðƷ�ɣ�\n");
                return 1;
}
// QCing.
