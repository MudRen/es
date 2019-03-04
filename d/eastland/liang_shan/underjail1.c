#include </d/eastland/liang_shan/takeda.h>
#include <conditions.h>

#define LONG1 "����һ�����صĶ��ߣ��Ұ�������ʪ��������ˮ����ͣ�Ĵӽ���һ����\n��(crack)�������������ѷ�Ĵ�С��Ӧ�ÿ���������ǿ���롣\n"
#define LONG2 "����һ��������ˮ�����ض��ߣ��̹ǵĺ��������������ı�ˮ������\n������Ͽ��뿪�˴������»�û����֮ǰ���ͻ��ȱ�������....\n" 
inherit ROOM;

void create()
{
	::create();
	set_short( "��ˮ����" );
        set( "long","@@query_long");	
        set("objects",(["skeleton" : "/d/eastland/liang_shan/obj/skeleton"]));
        set("underwater",1);
        
        reset();
}
string query_long()
{
    if ( !query("underwater")  )
      return LONG1;
    else
    return LONG2;
}

void init()
{
     UNDERWATER->apply_effect(this_player(),4,1);
     add_action("do_enter","enter");
     add_action("do_break","break");
     add_action("do_search","search");
}

int do_enter(string arg)
{
    if ( !arg || arg != "crack")
        return notify_fail("���� enter ������!\n");
 
    if ( query("underwater") )
 	return notify_fail("����û���κ����ܽ�����ѷ�...\n");
    write ("���þ����̵�������һͷ���˽�ȥ...\n");
    tell_room(this_object(),
    "�㿴��"+this_player()->query("c_name")+ "һͷ�����ǽ�ϵ�һ���ѷ�.....\n" ,
    this_player());
    this_player()->move_player(TROOM"underjail2","SNEAK");
return 1;
}
int do_break(string arg)
{
 object weapon;
 int wc;
 
         if ( !arg || arg != "wall")
         return notify_fail("���� break ������!\n");
         weapon = this_player()->query("weapon1");
         
         if ( !query("underwater") )
         return notify_fail("����û���κ����ܴ��Ƶ�ǽ...\n");
                 
         if ( !weapon && (string)this_player()->query("class") != "monk" &&
              (string)this_player()->query("class") != "mage") {
              write("���������ָ�ɮ���Ƿ�ʦ�ķ�������������Ǵ���ǽ�ڵ�...\n");
                   return 1;
                        }
         if ( !weapon ) {
         
         if ((string)this_player()->query("class") == "monk") { 
         write("���������֣���������������ƽ�ƣ���ǽӦ������...\n");
         tell_room(this_object(),
             "�㿴��"+this_player()->query("c_name")+ "������������ǽ�����һ���ѷ�..\n"
          ,this_player());
         this_player()->set("force_points",(int)this_player()->query("force_points")/2);
         }
         
         if ((string)this_player()->query("class") == "mage") {
         write("���������˻����������������ǽ���ϣ�һ����ը֮�ᣬ\n"
               "ǽӦ������...\n");
         tell_room(this_object(),
             "�㿴��"+this_player()->query("c_name")+ "�����ķ�����ǽ��ը��һ���ѷ�..\n"
             ,this_player());
         this_player()->set("spell_points",(int)this_player()->query("spell_points")/2);
         }}    
    else {
    write("���þ�ȫ����������������ϵ��������ɹ�\�ؽ�ǽ����һ���ѷ���������\n"
          "������Ҳ��������ˡ�\n");  
    tell_room(this_object(),
    "�㿴��"+this_player()->query("c_name")+ "������������ǽ�ڿ���һ���ѷ�..\n" ,
    this_player());
            wc = weapon->query("weapon_class");
            wc -= weapon->query("wc_damaged");
            if( !weapon->query("wc_damaged") ) {
                            weapon->add( "short", " (����)" );
                                    }
            delete("underwater");
            weapon->add( "wc_damaged", wc/2 );
            this_player()->calc_weapon_class();
    }
    write("��춴�����ˮ����մ��Ƶ��ѷ��������������ɼ��ı���ɺ�������\n"
          "���ѵ��������������յ���??\n");
    tell_room(this_object(),
    "��������һ����϶��������ˮ���Ƕ�������������"+this_player()->query("c_name")+ "��Ϊվ��̫����������\n"
    "�ĺ������ɣ�����Ϊվ�ıȽ�Զ���������....\n"
    ,this_player());
    "/d/eastland/liang_shan/underjail2"->set("exits/crack","/d/eastland/liang_shan/underjail1");
    this_player()->move_player(TROOM"underjail2","ͻȻһ���˱�һ�ɺ�ˮ���˹���");
return 1;
}
int do_search(string arg)
{
 if ( arg == "wall") {   
    write("����ϸ�ô�ÿ���ұڣ��㷢����һ���ط������ر�ն�...\n"
    "Ҳ��������跨������...\n");
    return 1;
    } 
 if ( arg == "crack" ) { 
 if ( query("underwater") ) {
 	write("����û���κ��ѷ�...\n");
 	return 0;
 	}
    write ("����ϸ�Ĺ۲�����ѷ죬Ӧ�ÿ���������ǿ����(enter)...\n");
    return 1;
    }
 else 
   write("����ˮ�������˰��죬���˼�Ӳ���ұڣ�����ûɶ�ر��!\n"); 
   return 1;
}
int clean_up() { return 0; }             