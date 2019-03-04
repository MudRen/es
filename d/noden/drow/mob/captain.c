#include "/d/noden/drow/iigima.h"

inherit MONSTER ;

void create ()
{

        ::create();
        set_level(15);
        set_name( "Captain Shukaise","�����ӳ��޿�˼" );
        add ("id", ({ "drow", "captain","shukaise" }) );
        set_short( "Captain Shukaise","�����ӳ��޿�˼" );
        set("unit","λ");
        set("alignment",700);
        set("weight",400);
        set("wealth/copper",6000);
        set_long(
@C_LONG
��λӢ�µ�սʿ�Ǻڰ������������ӳ���Ҳ��ʿ���ǵ��쵼��
���������Ѿ�����ʮ�����ˣ������������Ŀ�⻷�����ܣ�����
������Ϊʿ�����Ű��ݼٵ����ⷳ������
C_LONG
        );
        set_perm_stat("int", 20);
        set_perm_stat("dex",14);
        set_perm_stat("str",21);
        set("max_hp",480);
        set("hit_points",480);
        set_natural_weapon(20,10,20);
        set_natural_armor(32,15);
        set ("inquiry",([
                "certification" : "@@ask_certification",
                        ]) );
        set ("special_defense",(["all":30, "cold":-10,
                        "fire":-10, "divine":-30,"evil":30, "none":15]));
        set ("race", "drow");
        set ("gender", "male");
        set_skill("longblade",70);
        set_skill("dodge",60);
        set_skill("parry",70);
        set_skill("block",75);
        set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�"}));
        wield_weapon(OBJ"scale_lb");
        equip_armor(ARM"plate");
        equip_armor(ARM"shield");
        equip_armor(ARM"arms");
        equip_armor("/d/noden/asterism/armor/leggings02.c");
}

void die()
{
        object obj,who;
        tell_room(environment(this_object()),
                "�����ӳ�˵������......��...��û�Ŷ~~~~~~��\n");
        ::die(1);
}

int ask_certification()
{
        object obj;
        if (!this_player()->query_temp("drow_certi")
                || this_player()->query_temp("drow_certi") == 3 )
        {
                tell_object(this_player(),@LONG
�ӳ�ߺ�ȵ���ȥȥ��С���Ѳ�Ҫ����ߵ�����û��������æ��
LONG
                );
                return 1;
        }

        if (this_player()->query_temp("drow_certi") == 1 )
        {
                tell_object(this_player(),@LONG
�ӳ�̧��ͷ�����´�������һ�������ͷ˵���ţ������ǱȻ����аɣ�
�����㹻������Ƶ�����һ�����ߣ�Ϊ�˱�����˵Ĵ��ţ��Ҵ��㵽��Ӫ
��Ľ������ɡ�
LONG
                );
                tell_room(environment(this_object()),
                        "�㿴��"+(string)this_player()->query("c_name")+
                        "�����޿�˹�ӳ��߽���Ӫ�\n",this_player() );
                this_player()->move_player("/d/noden/drow/square1.c","SNEAK");
	call_out("message",5,this_player() );
                return 1;
        }

        if (this_player()->query_temp("drow_certi") == 2 )
        {
                tell_object(this_player(),@LONG
�޿�˹�ӳ�˵�����ţ����Ծ�������ͼ�ı����ˣ������������������ϣ�
�峤�ͻ�֪���ҵ���˼�ˡ�
LONG
                );
                obj = new("/d/noden/drow/obj/mark");
                obj->move(this_object() );
                command("give seal to "+(string)this_player()->query("name") );
                this_player()->set_temp("drow_certi",3);
                return 1;
        }
        return 1;
}
void message()
{
	tell_object(this_player(),@LONG
�������޿�˹�ӳ��������ӿ��д�����С���ѣ�������һ��Ϳ���
������α���������ߣ���취������ɡ�
LONG
	);
}
