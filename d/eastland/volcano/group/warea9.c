#include "../oldcat.h"

inherit ROOM;

int east_totem,west_totem,south_totem,north_totem;
int can_search_fire;

void create()
{
	::create();
    set_short("�����岿��㳡");
	set_long( 
@LONG_DESCRIPTION
�����ǰ����岿��㳡��ÿ���������Ǽ��䣬���еİ������˶���������ۻᣬ��
��������һ����ʯͷΧ������Ӫ�����������һ���������ȼ�գ��㳡�����ϱ�������
��ͼ�ڣ�ͼ���Ͽ���һЩ�����ͷ���������������ࡢ����ۡ����Ц��һ�ؽص�ͼ
��(totem)��ʾ������ḻ������������ʾ�����������Ȼ��һЩ�����η�塣
LONG_DESCRIPTION
	);
set( "exits", ([
     "south" : OGROUP"warea4",
     "north" : OGROUP"warea6",
     "east" : OGROUP"warea10" ]) );
set( "item_desc", ([
     "totem":"���ĸ�ͼ���ǰ�����������ᾧ����ע�⵽ÿ��ͼ�ڹ����ͷ�ƺ�����ת��(turn)��\n",
     "fire" : "@@look_fire",
     "tunnel" : "@@look_tunnel",
     ]) );
set("search_desc", ([
    "fire":"@@search_fire",
    ]) );
set_outside("eastland");
reset();
}

void init()
{
  add_action("do_turn","turn");
  add_action("do_enter","enter");
}

/* <east totem>=west, <south totem>=south, <west totem>=west, <north totem>=east
   then can see secret tunnel. */

string search_fire()
{ 
  string str;

  if (east_totem==3 && south_totem==2 && west_totem==3 && north_totem==1) {
    this_player()->set_temp("fire/check",1);
    return "���һ�Ϩ��֮�ᣬ����Ѱ����Ӫ�أ�����һ�������ص�(tunnel)����ڡ�\n";
  }
  return "�������һ�֮�£���ʲ�ᶯ������������ġ�\n";
}

string look_fire()
{
  if (east_totem==3 && south_totem==2 && west_totem==3 && north_totem==1) {
     return "�㷢��ԭ������������һ�ͻȻ��ʧ����Ӱ���١�\n";
  }
  return "һƬ�����һ���������Ӫ�����Լ�ҹ��ȼ������\n";
}

string look_tunnel()
{
  if(this_player()->query_temp("fire/check"))
    return "һ�������ص�����ڣ�����ڿ���ȥ��������ġ�\n";
  return "��Ҫ��ʲ��?\n";
}

int do_enter(string arg)
{
  if (!arg || arg!="tunnel")
    return 1;

  if (east_totem==3 && south_totem==2 && west_totem==3 && north_totem==1) {
   if (this_player()->query_temp("fire/check")) {
    east_totem=1;
    south_totem=1;
    west_totem=1;
    north_totem=1;
    write("\n���߽��ص���\n\n");
    this_player()->move_player(OGROUP"tunnel1","SNEAK");
    return 1;
   }
  }

  return 1;
}

int do_turn(string arg)
{
  string str1;

  if (!arg || arg=="")
    return notify_fail("The syntax: turn <direction> totem\n");

  if (sscanf(arg, "%s totem",str1) == 1) {
    switch(str1) {
    case "east" : switch(east_totem) {
                  case 4 :
                        write("�㽫����ͼ�ڵĹ���ͷת�򶫷���\n");
                        east_totem=1;
                        break;
                  case 2 :
                        write("�㽫����ͼ�ڵĹ���ͷת��������\n");
                        east_totem=3;
                        break;
                  case 1 :
                        write("�㽫����ͼ�ڵĹ���ͷת���Ϸ���\n");
                        east_totem=2;
                        break;
                  case 3 :
                        write("�㽫����ͼ�ڵĹ���ͷת�򱱷���\n");
                        east_totem=4;
                        break;
                  default:
                    return 1;
                  };
         break;
    case "west" : switch(west_totem) {
                  case 4 :
                        write("�㽫����ͼ�ڵĹ���ͷת�򶫷���\n");
                        west_totem=1;
                        break;
                  case 2 :
                        write("�㽫����ͼ�ڵĹ���ͷת��������\n");
                        west_totem=3;
                        break;
                  case 1 :
                        write("�㽫����ͼ�ڵĹ���ͷת���Ϸ���\n");
                        west_totem=2;
                        break;
                  case 3 :
                        write("�㽫����ͼ�ڵĹ���ͷת�򱱷���\n");
                        west_totem=4;
                        break;
                  default:
                    return 1;
                  };
         break;
    case "south" : switch(south_totem) {
                  case 4 :
                        write("�㽫�Ϸ�ͼ�ڵĹ���ͷת�򶫷���\n");
                        south_totem=1;
                        break;
                  case 2 :
                        write("�㽫�Ϸ�ͼ�ڵĹ���ͷת��������\n");
                        south_totem=3;
                        break;
                  case 1 :
                        write("�㽫�Ϸ�ͼ�ڵĹ���ͷת���Ϸ���\n");
                        south_totem=2;
                        break;
                  case 3 :
                        write("�㽫�Ϸ�ͼ�ڵĹ���ͷת�򱱷���\n");
                        south_totem=4;
                        break;
                  default:
                    return 1;
                  };
         break;
    case "north" : switch(north_totem) {
                  case 4 :
                        write("�㽫����ͼ�ڵĹ���ͷת�򶫷���\n");
                        north_totem=1;
                        break;
                  case 2 :
                        write("�㽫����ͼ�ڵĹ���ͷת��������\n");
                        north_totem=3;
                        break;
                  case 1 :
                        write("�㽫����ͼ�ڵĹ���ͷת���Ϸ���\n");
                        north_totem=2;
                        break;
                  case 3 :
                        write("�㽫����ͼ�ڵĹ���ͷת�򱱷���\n");
                        north_totem=4;
                        break;
                  default:
                    return 1;
                  };
          break;
    default :
          return notify_fail("The syntax: turn <direction> totem\n");
    }; 
    return 1;
  }
  return notify_fail("The syntax: turn <direction> totem\n");
}

void reset()
{
  ::reset();
  east_totem=1;
  west_totem=1;
  south_totem=1;
  north_totem=1;
  can_search_fire=0;
}
