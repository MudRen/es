// Created by Aquarius@EasternStory
#include "mudlib.h"
#define TIME 120 	// 120 ������ʧ
inherit OBJECT;
int droped = 0;		// �Ƿ��ѱ����ڵ���
int xx = 0;		// ����.. ��֮, ��Ҫ�� flag
int life=0;		// ��öͼ������Ч����
int dam=0;		// ����ɵ��˺� , dam = skill/5;
object tricker;		// ��ͼ������

void create()
{
     set_name("pushpin","ͼ��");
     set_short("ͼ��");
     set_long(@LONG
һ��ͼ��, ��������̫����, ������(spread)�ڵ���, ��С�Ĳȵ�����
һ����ʹ�����۽С�
LONG
      );
     set( "unit", "��");
     set("weight",5);
     set("value", ({ 50, "silver" }));
}

void init()
{
    object who,mount_ob,*obs,env;
    int i;
    mapping exits;
    string dir,*dirs;

	// ���ڶ�ĳ��(����)������, ��һ��ͬʱ�����������˲��ᱻ�̵� .
    if ( xx ) return ;

    if ( ! droped ) {
        add_action("do_spread","spread");
	return;
    }

    if ( life < time() ) {
	this_object()->remove();
	return ;
    }


    who = previous_object();
    env = environment(who);
    
    if( ! who || ! living(who) || who->query_temp("flying") ) 
	return ;

    if ( who == tricker && dam > random(23) ) {
	tell_object(who,"��С�ĵıܿ��Լ�����ͼ����\n");
	return ;
    }


    if ( random(dam) > 18 ) 
	return ;

    if ( (mount_ob = who->query_temp("mounting")) ){
	xx=1;
    	tell_object(who,
		set_color("�������ͻȻһ����˻,��������,����ˤ������!!\n","HIR",who));
	tell_room( environment(who),
		who->query("c_name") + "������ͻȻ�ҽ�һ��, ��"+who->query("c_name")+"ˤ�ڵ���.\n",who);
	who->block_attack(6);
	who->set_temp("msg_stop_attack","( �㱻ˤ��ʹ����, ��������, �޷����� )" );
//	call_other("/adm/daemons/mount","dismount",mount_ob,who);
	"/adm/daemons/mount"->dismount(mount_ob,who);
	// ���� .. ����д������ ...
//	mount_ob->set("moving",1);
//	mount_ob->set("speed",40);
	this_object()->remove();
    } else {
	xx = 1;
    	tell_object(who,
		set_color("�����һʹ, ����ʲ��̵���!!\n","HIR",who));
    	who->set_temp("msg_stop_attack","( ��Ľű���ס��, �������� )\n");
    	who->block_attack(4);
    	who->add("hit_points",-dam);
    	this_object()->remove();
    }
    return ;
}

int do_spread(string arg)
{
	object env,*inv;
	int skill,i,num;
	if ( ! arg || arg == "" || ! id(arg) )
		return 0;
	if ( (int)this_player()->query_skill("trick") < 5) {
		tell_object(this_player(),"�㱿�ֱ��ŵ�, ��С�Ĵ̵��Լ�, ʹ����!!\n");
		this_player()->add("hit_points",-10);
		return 1;
	}
	env = environment(this_player());
	inv = all_inventory(env);
	for(num = 0,i=sizeof(inv)-1;i>=0;i--)
		if ( (string) inv[i]->query("name") == "pushpin" )
			num++;

	if ( num > 2 ) {
		tell_object(this_player(),"�������ض���ͼ��, �ͱ���������\n");
		return 1;
	}

	tell_object(this_player(),
		"��ץ��һ��ͼ��, ͵͵�����ڵ��ϡ�\n");
	if( (int) this_player()->query_temp("hide_score") < 100  &&
	    this_player()->query("player_invisible") != 1 )
		tell_room(environment(this_player()),
	          sprintf("%s�е��������,��֪������ʲ�ᡣ\n",this_player()->query("c_name")), this_player() );
	life = time()+TIME;
	this_object()->set("prevent_get",1);
	this_object()->set("player_invisible",1);
	this_object()->move(env);
	tricker=this_player();
	dam = (int) this_player()->query_skill("trick")/5;
	droped = 1;
   	remove_action("do_spread","spread");
	return 1;	
}

