#include "../hawk.h"
inherit MONSTER;
void create()
{
        ::create();
        set_level(3);
	set("drink",0);
        set_name( "Traito","�׶�" );
        add("id",({"traito"}) );
        set_short( "�׶�" );
        set_long(@LONG
�㿴��һ�������С��Сͷ��������ӣ��������������֮�ǵ����һ��
����ࡡ��ԴӰ�������������������䣬�׶�ĵ�λ����������һ�����
�ϴܣ���������зһ�������˳��к��аԵ���
LONG
        );
        set( "inquiry", ([
                "wine" : "@@ask_wine",
                "vito" : "@@ask_vito",
                "plan" : "@@ask_plan",
                ]) );
        set( "alignment", -400 );
        set( "gender","male" );
	set( "max_hp",100 );
	set( "hit_points",99 );
        set( "race","hawkman" );
        set( "no_attack", 1 );
}

void init()
{
        add_action("to_inform","inform");
}

int to_inform()
{
        if (this_player()->query_temp("get_wine") != 2)
        {
                tell_object(this_player(),"�׶�˵���ɣ���������ҵ���\n");
                return 1;
        }

        else
        {
                tell_object(this_player(),@LONG
�׶�һ����������������Ķ��������˳��ĳ����ˡ�
LONG
                );
                this_object()->move("/d/std/rooms/void");
		call_out("come_back",40,this_object() );
                return 1;
        }
        return 1;
}

int come_back()
{
	object obj;
	message("tell_room","�㿴���׶�ҡҡ�λεĴ��������˽�����\n",
		HAWK"traroom",this_object() );
	obj = new(MOB"traitoa.c");
	obj->move(HAWK"traroom");
	this_object()->remove();
	return 1;

}

int ask_wine()
{
	if (!this_object()->query("drink") )
	{
        	tell_object(this_player(),@LONG
�׶�˵���ư�������ϲ�����ˡ���ʿ�ɰ��������ذ����Ҷ���ϲ���ġ�����
��˵������һ�ֳ��������ζ���ܺã���ϧ�������Ҷ���û�ȹ���������ܰ���
���õ����־����ȣ���һ����ܸ��˵ġ������ɣ����ȥ�����Ұɣ��ҵ�������
����(inform)�Ҿ����Ķ������Լ�ȥ�ȣ������ò��ð���
LONG
        );
        	this_player()->set_temp("get_wine",1);
        	return 1;
	}
	else
	{
		tell_object(this_player(),
			"�׶�˵���ƣ�....���Ѿ�������������������....\n");
		return 1;
	}
}

int ask_vito()
{

        if ((int)this_player()->query_temp("traito") == 1)
        {
                tell_object(this_player(),@LONG
�׶�˵���ٺ٣�����˿������������ȥ����������ά������Ѿ�����
�������������İɡ�����Ϊ������Ϊ�ܣ��ⲻ������ÿ��ٰ��䶷����ƾ�
����ľ����𣿲�Ҫ����ʲ�������ݺ��������������˾�Ҫ���䡣�������
�ţ�������ȥ�Ͱ����������������������....
LONG
                );
                this_player()->set_temp("traito",2);
                call_out("look_look",20,this_player());
                return 1;
        }
        else
        {
                tell_object(this_player(),@LONG
�׶�˵��ά�ࣿ��˭�������ʵ�....������������ǰ�����䣬����ȥ�걻�Լ���
�ܴܵ�ܣ��Ӵ˾Ͳ�����Ӱ�ˣ������Ǿ���û�����˰ɡ�
LONG
                );
                return 1;
        }
        return 1;
}

int ask_plan()
{
        if( this_player()->query_temp("smore_box") < 3) return 0;
        tell_object(this_player(),@LONG
�׶�������ɫ....������˵��
�����찡�����㶼֪��������....û�뵽....û�뵽���Ƕ�����������Ŭ����
ȫ������̰������! ��Ȼ�µ�����Ҿ͸����㱳������ܰɣ��������Ҫ��Ӧ
�Ұ����ڳ��ϼ�������ǰ���鰡��

����������������....����������Ϊ����Ҫ��ȡ��������Ĺھ����������ͻ�������
�µ�ʱ���ռ���������ҩ�ݣ�����ʳ�޵���Һ��������������һƿͨ���Ѫ����ҩ��
����֮�᲻������������������������Ƥ����ʯ��Ҳ�ѹֵ���������ά��Ҳ���
�ڰ���������°�! ����....���ҩ�и��������㣬���ǰ�����������ᣬ���ֳ��
����Ӳ������ëҲȫ�����ʻ������仰˵����Ϊ����������İ�����Ȼ�����ѽ!!

��������..........��������...............��������...........

�׶������Ц��ֹ�����ز��𣬾�ȻЦ����!!
�����أ��׶��ʬ��ð��һ�����̣�һ���֮�ᣬ����ʬ�徹Ȼ������!
�����Ӧ�ð��׶�Ļ�����(report)��������, Ҳ����Ի�ά��һ�����!

LONG
        );
        this_player()->set_temp("smore_box",4);
	this_object()->remove();
}

int look_look()
{
        tell_object(this_player(),@LONG
����һ�������ͻȻ�뵽�ո��׶���۾�һֱ������ǽ�ߵ�һ������
��(box)����֪���ڸ��
LONG
        );
        this_player()->set_temp("smore_box",1);
        return 1;
}

