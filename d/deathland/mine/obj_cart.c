
#include "../echobomber.h"
#include <uid.h>

inherit OBJECT;

object roomcart;

void create()
{
	seteuid(getuid());
	set_name( "Cisklyph cart", "ϣ˹�������˿�" );
	add( "id", ({ "cart" }) );
	set_short( "Cisklyph cart", "ϣ˹�������˿�" );
	set_long( "@@query_long", "@@query_c_long" );
	set( "prevent_get", 1 );
	set( "prevent_drop", 1 );
	set( "weight", 10000 );
}

void set_roomcart(object ob1) { roomcart=ob1; }
object query_roomcart() { return roomcart; }

string query_long()
{
	return
		"You see the Cisklyph cart. You can \"board\" it.\n";
}

string query_c_long()
{
	return
		"����һ̨ϣ˹�������˿�,�������Ҫ�����,����\n"
		"�� board ָ��.\n";
}

void init()
{
	add_action( "do_board", "board" );
}

int do_board(string arg)
{
	if( !arg || !id(arg) ) return 0;
	if ( roomcart->query("cart_moving") ) 
	   return notify_fail("���˿��������ƶ���.���޷�������.\n");
	this_player()->move_player( roomcart , ({
	  "%s board the cart.\n","%s �����˿�.\n","%s board the cart.\n","%s �������˿�.\n",
	  }));
	return 1;
}

void travel_mine()
{
     call_out("traveling",3);
}

void traveling()
{
     string dir;
     object *items,outside,cart;
     int i;
     
     cart=this_object();
     roomcart->set( "cart_moving" , 2 );
     outside = environment(cart);
     dir = outside->query("direction");
               
     switch ( dir ) {
        case "block":  
                        tell_room(outside,
                          "��ֻ������ײ��������. ��һЩ�˴ӳ����ﱻ�׳���.\n"
                          );
                        tell_room(roomcart,
                          "��Ȼ  ��һ��, ���Ӻ������ص�ײ�����ұ�\n"
                          "��̨���ӽ�����, ���㱻�׳��˳���......\n"
                          "�����������ת, һ��ͷ��Ŀѣ.\n"
                          );
                        items=all_inventory(roomcart);
                        for(i=0;i<sizeof(items);i++) { 
                          if ( living(items[i]) )  
                            items[i]->receive_damage(15);
                          items[i]->move(environment(cart));
                          }
                        roomcart->remove();
                        cart->remove();
                        break;
        case "machine":       
                        tell_room(outside,
                        "���ӷ�ʻ������һֱ���ڽ���ɷ����״̬, һЩ��½½����.\n"
                        "�ر��׳���.\n"
                        );
                        tell_room(roomcart,
                        "����һ�����ɷ����, ���ͣ������.\n"
                        "Ȼ����ȴ��С�ĵر����˳���.\n"
                         "�����������ת, һ��ͷ��Ŀѣ.\n"
                         "���˵������������\n"
                          );
                        items=all_inventory(roomcart);
                        for(i=0;i<sizeof(items);i++) 
                          items[i]->move(environment(cart));
                        roomcart->remove();
                        cart->remove();
                        tell_room(outside,
                        "ֻ��һЩ���˿󹤰ѿ󳵽���, Ѹ�ٶ���Ч�ʵؽ��������ǵĹ���.\n"
                        );  
                        break;
        case "abyss" : tell_room(outside,
                       "ֻ�����ӷ�Խ����Ԩ, �����˶���.\n"
                       );
                       tell_room(roomcart,
                       "��о������Ӻ����������.\n"
                       );
                       cart->move(outside->query("another"));
                       call_out("traveling",1);
                       break;
        case "special":tell_room(outside, 
                       "��������ӳ�����ʯ����, ������ʯ�ѵ�����.\n"
                       );
                       tell_room(roomcart,
                       "����ó��Ӻ���ײ����һ��ʯͷ.\n"
                       );
                       cart->move(outside->query("another"));
                       call_out("traveling",1);
                       break;
        default: 
               tell_room(outside,({
                 "You find the cart move out here and go "+dir+".\n",
                 "�㿴���˿��뿪������"+to_chinese(dir)+"����ʻ��ȥ.\n",
                 }),cart);           
               tell_room( roomcart,({ 
                 "The Cisklyph cart is moving very fast.\n",
                 "ϣ˹�������˿󳵷��ٵ��ƶ���.\n"
               }) );
     
               cart->move(outside->query("exits/"+dir));
               tell_room(environment(cart),({
                 "You find the cart moves in very fast.\n",
                 "�㿴��һ̨�˿󳵿��ٵس����...\n",
                 }),cart);
               
               call_out("traveling",1);
        };
        
}
