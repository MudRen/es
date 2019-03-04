

#include "../echobomber.h"
inherit OBJECT;

void create()
{
  seteuid(getuid());
  set_name("Ancient Evil Spirit","�Ŵ�а������");
  
  set_short("Ancient Evil Spirit","�Ŵ�а������");
  set("c_long",@ScryBall
�������ĹŴ�а������, �����ͷ�����ʱ��, �������������ų���
�ĵط�, ���㽫��֪�������һ��һ��, ֱ��������ٵ�Ϊֹ.
--Use <info spirit> ��ø���ϸ������.
ScryBall
);
  add("id",({"spirit",}));
  set( "unit", "��");
  set("weight", 0);
  set("c_extra_look","$N�������������µ����Χ������.\n");
  set("prevent_drop",1);
  set("prevent_insert",1);
}

void init()
{
    add_action("to_info","info");
    add_action("to_scry","scry");
    add_action("to_toss","toss");
    add_action("to_release","release");
}

int to_release(string str)
{
    string room;
    if (!id(str)) 
      return 0;
    if (query("release")) 
      return notify_fail("������Ѿ����ͷų�����.\n");
    
    room = file_name( environment( this_player() ) );
    
    set("where",room);
    
    set("release",1);
    write("���������ͷų��Ŵ�а�������.\n");
    return 1;     
}

int to_scry(string str)
{
    object room,*item;
    int chinese_mode;
    string room_desc,desc;
    
    if (!id(str)) 
      return 0;
    if (!query("release")) 
      return notify_fail("�������δ���ͷų���.\n");
    
    room_desc = query("where");
    chinese_mode=can_read_chinese();
    if ( !(room = find_object( room_desc )) ) room=new(room_desc);
    desc=call_other("/cmds/std/_look","remote_look_room",room,0,1,chinese_mode);
    write(desc);
    return 1;      
}

int to_toss(string str)
{
    if (!id(str)) return 0;
    write("��ѹŴ�а�������ٵ���.\n");
    this_object()->remove();
    return 1;
}

int to_info(string str)
{
    if (!id(str)) return 0;
    
    write(
    "------------------------\n"
    "�ͷ����: release spirit\n"
    "���ӷ���  scry spirit   \n"
    "�ٵ����  toss spirit   \n"
    );
    return 1;
}

