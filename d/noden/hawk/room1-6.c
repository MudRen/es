//room1-6.c
#include <mudlib.h>
#include <stats.h>
#include <conditions.h>
#include "mudlib.h"
#include "hawk.h"
inherit ROOM;
int moves;
void create()
{
        ::create();
        set_short("ʯ��С��");
        set_light(1);
        set_long( @LONG_DESCRIPTION
�ߵ����ԶԶ������Կ���һ�����͹�״�ĳǣ��������������ֵ��ǣ�
�������ƺ��ڻ������ƶ��������Ե�ɭ��(forest)������������࣬�������ȥ
��Ϊ����Ǳ���ԭ�ϰɡ�
    ��ע��·�ߴ���һ�����ˮ�����������Ĵ����������Ǹ㲻���������
�Ǵ��ıߴ����ġ�
LONG_DESCRIPTION
        );
          set( "exits", ([
                  "southwest" : HAWK"room1-7",
                  "north" : HAWK"room1-5",
                  ]) );
        set("c_item_desc",([
                "forest":"@@to_forest",
                "fountain":"@@to_fountain"
                ]) );
        reset();
}//end of creat

void init()
{
        add_action("do_search","search");
        add_action("to_drink","drink");
        add_action("to_bottom","go");
}

int to_bottom(string str)
{
        if (!str || str=="southwest" || str=="north" )
                return 0;
        write("��! ����....\n\n");
        tell_room(environment(this_player()),
                "�㿴������ʧ����!\n",this_player());
        this_player()->receive_damage(70);
        this_player()->move_player(HAWK"room1-18","SNEAK");
        tell_room(environment(this_player()),
                "�㿴��"+(string)this_player()->query("c_name")+
                "�Ӹ��ʵľ�����ˤ����!\n"+
                "��Ȼû��! ��������!\n",this_player());
        return 1;
}

string to_forest()
{
        return "����ɭ�ֶ������ù�ͺͺ�ģ��ѵ���Щ�˶�������Ҫˮ�������𣿣�\n";
}

int to_drink(string s)
{
        if ((s == "fountain") || (s == "water"))
        {
                if (moves == 0)
                {
                        tell_object(this_player(),"What?\n");
                        return 1;
                }

                if (moves == 3)
                {
                        tell_object(this_player(),@LONG
ˮ�Ѿ����ȹ���ˣ��㲻����ʼ�����ĸ����������ûˮ�ȡ�
LONG
                        );
                        return 1;
                }  

                if ( ( this_player()->query_temp("touch_ball")==1) &&
                        (this_player()->query_temp("drink_water")==0) )
                {
                        tell_object(this_player(),
                        "�����Ϳ�������ˮ�أ�Ŭ���Ŀ�ʼ��ˮ�����ˮ��\n");
                        this_player()->set_temp("drink_water",1);
                        (CONDITION_PREFIX + "simple_poison")->
                                apply_effect( this_player(),8, 10 );
                return 1;
                }
                if ( this_player()->query_temp("touch_ball") == 0)
                {
                        tell_object(this_player(),
                        "����˼��ڣ��;���ȫ����Ծ�����ǰһƬ������ð��"+
                        "�����߿���Ѫ��\n��е�һ����ԣ�һת�����Ѿ����ڵ���"+
                        "���������ˡ�\n");
                        (CONDITION_PREFIX + "simple_poison")->
                                apply_effect( this_player(),8, 10 );
                        (CONDITION_PREFIX + "slow")->
                                apply_effect( this_player(),8, 5 );
                        (CONDITION_PREFIX + "bleeding")->
                                apply_effect( this_player(),8, 8, 10 );
                return 1;
                }

                if (this_player()->query_temp("drink_water") == 1);
                {
                        tell_object(this_player(),
                        "��һ�ڽ���һ�ڵİ�ˮ�����ˮ�������ˣ���Χ���˶���"+
                        "�������ҵ�������\n�������������ĵ����㻹�ǱȲ�������"+
                        "���ϵĲ�ʹ������û��Ǻú�Ъ����Ƚ�ǡ����\n");
                        (CONDITION_PREFIX + "simple_poison")->
                                apply_effect( this_player(),8, 10 );
                        this_player()->set_temp("drink_water",2);
                        moves = 3;
                return 1;
                }
		
        }
        if ((s != "water") && (s != "fountain"))
        {
                tell_object(this_player(),
                        "What?\n");
                return 1;
        }
}
int do_search(string s)
{
        object obj;
        if (s == "forest")
        {
        	moves = 1;
        	tell_object(this_player(),@LONG
����ɭ�ֵ���ҵ���һ���峹��СϪ��ԭ��������ո�������ˮ����
�������������������ߣ�������һ����������ɫ����ˮ��(fountain)��
�����������֣���֪�������Ȫ�ط�����߸��
LONG
		);

		call_out("smell",10,this_player() );
        	return 1;
        	}

        if (s == "fountain")
        {
        switch(moves)
                {
                case 3:
                        tell_object(this_player(),
                                "������ˮ�ص׳�����̦���ҵ�һ��СֽƬ��\n");
                        obj = new("/u/s/smore/obj/paper.c");
                        obj->move(this_player());
                        moves = 4;
                        return 1;
                case 2:
                        tell_object(this_player(),
                                "�������������Ȫ....�����������"+
                                "��ˮ....�����뻹�����ˡ�\n");
                        return 1;
                case 1:
                        tell_object(this_player(),
                                "�����û�»��ǲ�Ҫ�������ȽϺã�\n");
                        return 1;

                case 0:
                        tell_object(this_player(),
                                "���������ң���û�з����κζ�����\n");
                        return 1;
                case 4:
                        tell_object(this_player(),
                                "���������ң���û�з����κζ�����\n");
                        return 1;
                }
        }

        if ((s != "fountain") || (s != "forest"))
        {
                tell_object(this_player(),
                        "���������ң���û�з����κζ�����\n");
                return 1;
        }
}

string to_fountain()
{
        if (moves == 0)
        {
                return "��������Ȫ����������ͷ�˰�....\n";
        }

        if (moves == 1)
        {
                moves = 2;
                return "����һ�����ʧ�޵���ˮ�أ��ر߳�������̦����������"+
                       "�������ȪˮҲ��Ⱦ�ɶ��ĵ���ɫ����˿������ƺ��"+
                       "���ף����������滹�᲻����ɶ���ĵĶ����������档\n";
        }
        if ((moves == 3) || (moves == 4))
        {
                return "��ˮ�ص�ˮ��֪����˭���ȵ�һǬ�����ˡ�\n";
        }
}

int smell()
{
	string name;
	name = (string)this_player()->query("name");
	tell_object(this_player(),
		"���Ȼ���ÿ�Ǭ��������ǵ�����ɱ�������۰ɡ�" );
	if (present(name,this_object() ))
	{
		tell_object(this_player(),@LONG
�㿴����ǰ��Ȫˮ....
������ǿ���Ժ�(drink)....
LONG
		);
		return 1;
	}
	tell_object(this_player(),@LONG
���뵽�ո��ҵ����Ǹ�
��ˮ��(fountain)��������Ȼ���ģ�������(drink)һЩӦ��û�д󰭡�
LONG
	);
	return 1;
}

void reset()
{
        ::reset();
        moves = 0;
}
