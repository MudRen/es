#include <uid.h>
#include <mudlib.h>
#include <daemons.h>

#define CAMP_FILE "/open/camp/"+(string)this_player()->query("name")+"_incamp.c"
#define SOURCE_FILE "/d/adventurer/hall/incamp.c"

inherit REF_D;
inherit DAEMON ;
inherit OBJECT;

void create()
{
	seteuid(getuid());
        set_name( "camp tools","¶Ӫ���߰�" );
	add( "id",({"camp","tool","camp tool"}) );
	set_short(set_color("¶Ӫ���߰�","HIB"));
	set_long("����һ��װ��Ӫ����Ӫ�ʣ���ˮ����˯��ȹ��ߵ�С������\n"
                 "�����ʹ������Ұ�⽨��(build)һ����ů��С����\n");
	set("unit","��");
	set("no_sale",1);
	set("weight",300);
        set("value",({ 3000,"silver" }));
        set("size",1);
        set("prevent_drop",1) ;
}

void init()
{
	add_action("help_camp","help");
	add_action("cmd_build","build");
        add_action("cmd_setsize","setsize");
}
int copy_file(string from, string to) {
    string str;
            str = read_file(from);
            if (file_exists(to))  rm(to);
            write_file(to,str);
            return 1;
}
void do_camp(object me, int skill, int size )
{ 
   object camp;
   string b_name,e_name;

   camp = new("/obj/camp");
   camp->move(environment(me));
   camp->set("size",size);
   camp->set("skill",skill);
   camp->set("last_locate",environment(me));
   b_name = me->query("c_name");
   e_name = me->query("name");   
   camp->set("creater",b_name);
   camp->set("creater_name",e_name);
   if (file_exists(CAMP_FILE)) rm(CAMP_FILE);
   write_file(CAMP_FILE,"inherit \""+SOURCE_FILE+"\";");
//   cp(SOURCE_FILE,CAMP_FILE);
   camp->set("TO_WHERE",CAMP_FILE);
   me->delete_temp("block_command");
   this_object()->remove();
   return;
}

int cmd_setsize(string size)
{
    if(!size)
        return notify_fail("���ڵ�Ӫ�ʴ�С�趨�� "+ this_player()->query("camp_size") +"
���ʡ�\n�÷������ help camp��\n") ;
    switch(size)
       {
          case "1" : this_player()->set("camp_size", 1 ) ;
                     write("���ڵ�Ӫ�ʴ�С�趨�� "+ size +"���� ��\n") ;
                     break ;
          case "2" : this_player()->set("camp_size", 2 ) ;
                     write("���ڵ�Ӫ�ʴ�С�趨�� "+ size +"���� ��\n") ;
                     break ;
          case "3" : this_player()->set("camp_size", 3 ) ;
                     write("���ڵ�Ӫ�ʴ�С�趨�� "+ size +"���� ��\n") ;
                     break ;
          case "4" : this_player()->set("camp_size", 4 ) ;
                     write("���ڵ�Ӫ�ʴ�С�趨�� "+ size +"���� ��\n") ;
                     break ;
          case "5" : this_player()->set("camp_size", 5 ) ;
                     write("���ڵ�Ӫ�ʴ�С�趨�� "+ size +"���� ��\n") ;
                     break ;
          case "6" : this_player()->set("camp_size", 6 ) ;
                     write("���ڵ�Ӫ�ʴ�С�趨�� "+ size +"���� ��\n") ;
                     break ;

          default  : write("�÷������ help camp��\n") ;
                     break ;
        }
    return 1;
}
int cmd_build(string str)
{
    int skill, hp, alignment,time, size;
    object me,env;
	
    me = this_player();
    env = environment(me) ;
    skill = (int)me->query_skill("camp");
    size = this_player()->query("camp_size");
    time =  6 + size*2 - skill/10 ;
     
    if (!str || str!="camp") return 0 ;
    if( !skill ) return notify_fail("��û��ѧ����Ӫ�������޷���������..��\n");
    if( skill < size*10 ) return
notify_fail("�����Ӫ���ɲ����Դ������������� ��\n");
    if( (int)me->query_attacker()) {
      write("��ս������Ӫ����Ҫ���Ϻ��ݲ���\n");
      tell_room( env, me->query("c_name") + "����ս������Ӫ���ѵ��������Ϻ��ݲ���\n",me) ;
      return 1;
    }
    if( !environment(me)->query("outside") )
            return notify_fail("����ĵ���̫Ӳ�����ʺϴ����\n");
    if( env->query( "underwater" ) )
            return notify_fail("��ˮ�д����ﲻ�Ǹ������⡣\n");
    if( env->query( "flamezone" ) )
            return notify_fail("�������ร����˿���������յ���\n");        
    if( env->query_temp( "adv_camp" ) )
	return notify_fail("�����Ѿ��б����ȴ������ˡ�\n");
    write("��������䣬�����﹤���ó������������ٶȿ�ʼ�����\n");
    		
    tell_room( env, 
	me->query("c_name")+"�������䣬�����﹤���ó������������ٶȿ�ʼ�����\n",
		me );

    env->set_temp("adv_camp", 1);
    if( !wizardp( me ) ) {
	me->set_temp("block_command", 1 );
    }		
    call_out( "do_camp", time , me, skill, size );
    return 1;
}


int help_camp(string str)
{
    if (!str || ( str!="camp" && str!="build" ) ) return 0 ;
    write(@HELP
Syntax: build camp 

����ʹ�� build ���ָ���������ڵĵط����ʵĻ������
�������ڵķ��������һ�����һ�䷿��ֻ�ܽ�һ���������
����˯�߻���Ϣ����ӿ����������������������Լ�̸�������ָ�
���ٶȣ�������˯��ʱ���ܹ������ܿ��ܾͻ����һ˯���ѡ�
��Ҳ����ʹ��setsize ���ָ���趨���������ʹ�ã�ͨ����Խ
�������������Խ����ˣ���Ϣ��Ч�����ã�����ҪԽ�õ�ʱ����
Խ�ߵļ�������������
��õ�������ܱ�������������Ե��㲻��ʱ�����ϲ�(destroy)
�����ǱȽϺõ�������
HELP
	);
    return 1;
}
