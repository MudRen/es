

#include <mudlib.h>
inherit OBJECT;
 
mapping levels = ([]); 

void create()
{
    seteuid(getuid());
    set_name( "a half tail", "�����β��" );
    add( "id", ({ "tail", "half" }) );
    set_short( "wolf tail", "�����β��" );
	set_long(
"\n",
"����ɫ��Э�������. �������֪���������, ���� <wolfinfo>. \n\n",
    );
    set( "weight", 2 );
    set( "no_sell", 1 );
    set( "prevent_drop",1);
    set( "extra_look", "$N is a member of C.W.A.\n");
    set( "c_extra_look", "$N��һֻ���������β�͵�������, �����޷���ɫ��\n");
    set( "unit", "��" );
}
 
void init()
{
	add_action("wolf_cmd","wolfinfo");
	add_action("wolves","wolves");
	add_action("rmall","rmall");
	add_action("bark", "bark");
	add_action("wtalk","wtalk");
	add_action("enemies", "enemies");
}


int bark(string str)  {
	object dest;

	if(!str || str=="") {
		write(can_read_chinese()?
"�㷢��һ��޺�!  woooof...  �뵽β�ͱ�"+this_player()->query_temp("c_cutter")+"������, ����һͷײ������.\n" :
"You bark like a wolf! Woof! Woof!\n");
		tell_room(environment(this_player()), ({
this_player()->query("c_cap_name")+"����һ����İ���!\n",
this_player()->query("cap_name")+" barks like a wolf! Woof! Woof!\n" }),
		this_player());
		return 1;
	}
	if(!dest=present(str,environment(this_player())))
		return notify_fail(can_read_chinese()?
"��Ҫ��ʲ�ᶫ����?\n" : 
"What do you want to bark at?");
		
	write(can_read_chinese()?
"�����"+dest->query("c_cap_name")+"���������ĵͺ�, ��ͼ����������Ĳ���֮��.\n" :
"You bark at "+dest->query("cap_name"));

	tell_object(dest, can_read_chinese(dest)?
this_player()->query("c_cap_name")+
"���㷢��һ�����Ŀ޺�, ������������Ĳ���֮��.\n" :
this_player()->query("cap_name")+" wolf cries sadly to you\n");
	return(1);
}


int wolves(string str) {
	object *wolves_online;
	int i;

	if(str=="all") { cat("/u/s/supertramp/cwa/memberlist.txt");return(1); }

	wolves_online=filter_array(users(),"filter_wolf",this_object());
	wolves_online=sort_array(wolves_online,"sort_usrs",this_object());
	i=sizeof(wolves_online);
	if(i) {
		write(can_read_chinese()?
"Ŀǰ���� "+i+" ֻɫ����ɫ:\n" : 
"There are "+i+" color wolves on line:\n");
		write("========================\n");
		while(i--)  {
			printf("[%2d] %s\n",wolves_online[i]->query_level(),
	wolves_online[i]->query(can_read_chinese()?"c_short":"short"));
		}
		write("========================\n");
	} else write(can_read_chinese()?
"��������һֻɫ��Ҳû��!\n" :
"There is no color wolf on line now\n");
	return 1;
}


int enemies() {
        object *wka;
        int i;

        wka=filter_array(users(),"filter_wka",this_object());
        wka=sort_array(wka,"sort_usrs",this_object());
        i=sizeof(wka);
        if(i) {
                write(can_read_chinese()?
"������"+i+"�� WKA �ں�֮������\n" :
"There are "+i+" WKA member(s) on line.\n");
                write("========================\n");
                while(i--)  {
                        printf("[%2d] %s\n", wka[i]->query_level(),
wka[i]->query(can_read_chinese()? "c_short" : "short"));
                }
                write("========================\n");
        } else write(can_read_chinese()?
"����̫��! WKA ����������!\n" :
"There is NO WKA member on line now!\n");
        return 1;
}


int filter_wka(object ausr)  {

        if((int)ausr->query("WKA")==1 && visible(ausr,this_player()))
        {
                levels[ausr]=(int)ausr->query_level();
                if(!levels[ausr] || levels[ausr]==0) return 0;
                return 1;
        }
        return 0;
}




int wtalk(string str)  {
        object *wolves_online;
        int i;

        if (!str || str=="") return notify_fail(can_read_chinese()?
"�������������˵ɶ?\n" : "What do you wanna tell other wolves?\n");

        wolves_online=filter_array(users(),"filter_wolf",this_object());
        wolves_online=sort_array(wolves_online,"sort_usrs",this_object());
        i = sizeof(wolves_online);

        if(i==1) return notify_fail(can_read_chinese()?
"����ֻ����һƥ��������, ����ʡʡ��Ŀ�ˮ��!\n" :
"You are the ONLY wolf on line now!\n");

        while(i--)  {
                message("wolf_line",sprintf(can_read_chinese(wolves_online[i])?
"[����] %s: %s\n":"[WOLF] %s: %s\n",this_player()->query(can_read_chinese(
wolves_online[i])? "c_cap_name":"cap_name"), str), wolves_online[i]);
        }
        return 1;
}



int sort_usrs(object u1, object u2)
{
	return (int)levels[u1]-(int)levels[u2];
}

int filter_wolf(object ausr)
{
	if ((int)ausr->query("CWA")==1 && visible(ausr,this_player()))
	{
		levels[ausr]=(int)ausr->query_level();
		if(!levels[ausr] || levels[ausr]==0) return 0;
		return 1;
	}
	return 0;
}

 
int wolf_cmd()
{
        cat("/u/s/supertramp/cwa/info.txt");
        return 1;
}

int rmall(string str)  {
	string cap_name, c_cap_name;
	object dest;

	cap_name=(string)this_player()->query("cap_name");
	c_cap_name=(string)this_player()->query("c_cap_name");

	if (!str || str =="")
	{
		write(can_read_chinese()?
"���ڴ�ͥ����֮���ѹ��·�! ���뵽β�ͱ�"+this_player()->query_temp("c_cutter")+"�����, �߲ѻں�\n�������ʱð����ͷ!\n" :
"You take off your all clothes.\n");

		tell_room(environment(this_player()), ({
this_player()->query("cap_name")+" takes off all clothes in front of you!\n",
c_cap_name+"������ǰ�ѹ������·�, ���ܵ������Ƶذ�������һ��,\n"+
"�����ٶ���һ��, ԭ��"+c_cap_name+"��һֻֻʣ���β�͵�������!\n"
		}), this_player());
		return 1;
	}
	if(!dest=present(str,environment(this_player())))
		return notify_fail(can_read_chinese()?
"��˭���·�?\n" :
"To whom you wanna take off the clothes?\n");
	
	if(!living(dest) || (int)dest->query("npc"))
		return notify_fail(can_read_chinese()?
"���ڶ�ţ������?\n" :
"Oops! You must have a SPECIAL taste!\n");

	write(can_read_chinese()?
"���"+dest->query("c_cap_name")+"�ѹ��·�! ���������㲻м�ĳ�Ц! \n" :
"You take off all clothes before "+dest->query("cap_name"));
	tell_object(dest, can_read_chinese(dest)?
c_cap_name+"������������·��ѹ�, ��һ�۾Ϳ�������ʣ��صĿ���β��, \nʵ���̲�ס��������Ц����! ��! ��! ��!\n" :
cap_name+" removes all clothes in front of you. You can't help yourself\nnot to laugh at him because you see his tail has been cut!\n");
	return(1);
}


string query_auto_load() { return("/u/s/supertramp/cwa/cwa_ob"+":"); }


