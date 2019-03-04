//#pragma save_binary

// _auction.c
// Command to auction an item .
// Created by Ruby@Eastern_Story, 6-11-94

#include <mudlib.h>

inherit DAEMON;
inherit COINVALUE ;
#define STOREROOM "/d/noden/farwind/auc_room.c"

int help()
{
        write(@HELP_TEXT
Syntax	: auction on/off
	��/�ص������㲥��
	: auction <something> for <price>
	�������ϵ�ĳһ����Ʒ����� price ö���ҡ�����㶨�����̫�ͣ�
	������˾�����㶨���ü۸�
	: auction <price>
	�� <price> ö����������������������Ʒ��

HELP_TEXT
);
        return 1;
}

object custom,buyer,auc_item;
int last_price,val;
int first = 1 ;
int auction_now = 0 ;

int check_auction()
{
	if (auction_now) {
//	if ( find_call_out("count_down") != -1 ) {
		write("�Բ�������������Ʒ�У����Ժ� !!\n");
		return 0;
	}
	return 1;
}

int boardcast(string msg)
{
        object *usr;
        int i;

	usr = users();
        if( sizeof(usr) )
                for( i=sizeof(usr)-1; i >= 0; i-- ) {
			if (!usr[i]->query("seller_channel")) continue;
			usr[i]->quick_message(
				sprintf(set_color("[������Ů��] :","HIY",usr[i])+" %s \n",msg),usr[i]);
		}
        return 1;
}
int channel_on()
{
        this_player()->set("seller_channel",1);
        write(set_color("��Ķ��ߴ���һ����ֵ���������ӭ���������㲥�� ..\n","HIY",this_player()));
        return 1;
}
int channel_off()
{
        this_player()->delete("seller_channel");
	write(set_color("��ŤŤ��Ķ��䣬�ص������㲥�������� ..\n","HIY",this_player()));
        return 1;
}

void count_down(int timer, int price)
{
	if ( last_price > price ) { 
		price = last_price ;
		call_out("count_down",9,1,price);
		return ;
 	}

	if ( nullp(custom) ) {
		boardcast("�� .. ���� Quit �� .. ����ȡ�� ..");
		if ( !nullp(auc_item) )
			auc_item->delete("prevent_get");
		auction_now = 0;
		buyer = 0;
		return ;
	}

	if ( nullp(auc_item) ) {
                boardcast("�� .. ����Ʒ��ʧ�� .. ����ȡ�� ..");
                auction_now = 0;
                buyer = 0;
                return ;
	}
	if ( timer<3 ) {
		boardcast(
//			  sprintf("%s���۵�%sһ������ %d �κ��� %d ö���� !! ����� !!",
			  sprintf("%sһ������ %d �κ��� %d ö���� !! ����� !!",
//				  custom->query("c_name"),
				  auc_item->query("short"),
				  timer,price));

                call_out("count_down",8,timer+1,price);
		return ;
	}
	if ( buyer ) {
		if ((int)buyer->query("wealth/silver") > price ) {

			buyer->add("wealth/silver",-price);
//              boardcast(sprintf("%sһ�� !! �� %d ö��������%s��лл�ݹ� !!",
                boardcast(sprintf("%sһ�� !! �� %d ö����������лл�ݹ� !!",
				  auc_item->query("short"),price,
//				  buyer->query("c_name")
				  ));
		if (custom) {				  
                	tell_object(custom,
			sprintf("�����������%s���۵� 50 %% ����������õ��� %d ö���� !! \n",
				auc_item->query("c_name"),val + (price-val)/2));
                        custom->add("wealth/silver",val + ( price-val)/2);
		}
		tell_object(buyer,
			"һֻ������ȿ�ݹ�˾ñ�ӵ�½����ɱ���������һ��������������ǰ��\n�֡��ݡ�������һ���ܵ��ˡ�\n");
		tell_room(environment(buyer),
			sprintf("һֻ����ĳĳ��ݹ�˾ñ�ӵ�½����ɱ���������һ����������%s��\nȻ���ַ�Ҳ�Ƶ����ˡ�\n",buyer->query("c_name")),buyer);
		
		environment(auc_item)->add("money",(price-val)/2);
		auc_item->move(environment(buyer));

		} else {
		tell_object(buyer,"һ�������Ƶ���������Ķ�������������ƭΰ���������˾�𣿸���һ���ѵ !!\n");
                environment(auc_item)->add("money",(int)buyer->query("wealth/silver")-1);
		buyer->set("wealth/silver",0);
                if (custom ) {
                	tell_object(custom,
			"һֻ������ȿ�ݹ�˾ñ�ӵ�½����ɱ���������һ��������������ǰ��\n�֡��ݡ�������һ���ܵ��ˡ�\n"
			"�浹ù������һ��ûǮ�ı�ƭ�ӣ��������ڵ�������ʧ���� !!\n");

                	tell_room(environment(custom),
			sprintf("һֻ����ĳĳ��ݹ�˾ñ�ӵ�½����ɱ���������һ����������%s��\nȻ���ַ�Ҳ�Ƶ����ˡ�\n",custom->query("c_name")),custom);
                	auc_item->move(environment(custom));
		}
		
		}
		
	}
	else {
		boardcast(sprintf("%s�Ų����� %d ö���ң���Ȼû��������̫������ !!",auc_item->query("short"),price));
                tell_object(custom,"���� !! ��̫̰���˰ɣ���ֵǮ�Ķ���Ҳ ...\n"
                        "һֻ������ȿ�ݹ�˾ñ�ӵ�½����ɱ���������һ��������������ǰ��\n�֡��ݡ�������һ���ܵ��ˡ�\n");
                tell_room(environment(custom),
			sprintf("һֻ����ĳĳ��ݹ�˾ñ�ӵ�½����ɱ���������һ����������%s��\nȻ���ַ�Ҳ�Ƶ����ˡ�\n",custom->query("c_name")),custom);
                auc_item->move(environment(custom));

	}
	auc_item->delete("prevent_get");
	auction_now = 0;
        first=1;
	buyer = 0;
	return ;
}

int cmd_auction(string str)
{
	string item,file;
	object ob1,room,*obs;
	int price1,bid_price,i;
	mixed *value ;

	if ( !room = find_object(STOREROOM) ) 
		room = new(STOREROOM);
	if (!str || !stringp (str)) return help();
	if (str == "on" ) return channel_on();

        if (str == "off" ) return channel_off();

        if (!this_player()->query("seller_channel"))
		return notify_fail("���ȴ������㲥����\n");

	if ((sscanf(str,"%s for %d",item,price1) != 2) && 
	    (sscanf(str,"%d",bid_price) != 1)) return help();

	if ( item ) {
	if ( !(ob1=present (item,this_player()))) 
		return notify_fail("����������������û��������� !!\n");

    if ( find_call_out("count_down") != -1 ) 
    	return notify_fail("�Բ�������������Ʒ�У����Ժ� !!\n");

	if ( (ob1->query("prevent_drop")) || (ob1->query("no_sale")) ||
		(ob1->query("prevent_insert")) )
		return notify_fail("�Բ��� !! ���ֶ����������� !!\n");
/*
	if ( obs = deep_inventory(ob1) ) {
		for ( i = sizeof(obs)-1 ; i >=0; i-- )
			if ( obs[i]->query("no_sale") )
				return notify_fail("������װ�˲��������Ķ��� !!\n");
	}
*/		
        if ( price1 < 1 ) return notify_fail("Ǯ̫���𣿱����� ^oo^ \n");
        custom = this_player();
        value = ob1->query("value");
    	if ( !value || !intp(value[0]) ) {
			return notify_fail("�Բ��� !! ���ֶ����������� !!\n");
	}
	val = value[0] * coinvalue( value[1] ) / coinvalue("silver");
	price1 = ( val > price1 ? val : price1 ) ;
	last_price = price1 ;
	
	auc_item = ob1;
	ob1->move(room);
	ob1->set("prevent_get",1);
	auction_now = 1;
                tell_object(custom,
			"һֻ������ȿ�ݹ�˾ñ�ӵ�½����ɱ����������������Ʒ���ߣ�\n�֡��ݡ�������һ���ܵ��ˡ�\n");
                tell_room(environment(custom),
			sprintf("һֻ����ĳĳ��ݹ�˾ñ�ӵ�½����ɱ�������������%s��һ��������\nȻ���ַ�Ҳ�Ƶ����ˡ�\n",custom->query("c_name")),custom);

		boardcast(
//			sprintf("��¥������ !! %s����%s(%s)һ�� !!\n��� %d ö���� !! ��û����Ҫ���۵İ���",
			sprintf("��¥������ !! %s(%s)һ�� !!\n��� %d ö���� !! ��û����Ҫ���۵İ���",
//			  custom->query("c_name"),
			  auc_item->query("short"),
			  auc_item->query("name"),
			  price1));

		call_out("count_down",9,1,price1);

	    return 1;
	}
	else if ( bid_price > 0 ) {

	if ( !auction_now )
		return notify_fail("�����Ҫ��ʲ�᣿������û��������\n");
	if (this_player() == custom ) 
		return notify_fail("ι ! ����������Ү�����̧�۸���\n");
	if (this_player() == buyer )
		return notify_fail("��ļ����Ѿ�����߼��� !!\n");
	if ( (int)this_player()->query("wealth/silver") < bid_price )
		return notify_fail("�����ϵ����Ҳ��� !!\n");
        if (first) {
	if ( bid_price <= last_price )
		return notify_fail("����ļ�Ҫ��춵׼�� !!\n");
             first=0;
                   } else
	if ( bid_price < last_price+50 )
		return notify_fail("����ļ�Ҫ������ڵļ۸��ټ� 50 ö����� !!\n");
	buyer = this_player();
	if ( nullp(buyer) ) return 1;
	last_price = bid_price;
//	boardcast( sprintf("%s���� %d ö��������%s !! ��û����Ҫ�Ӽ۵ģ�",
	boardcast( sprintf("���˳��� %d ö��������%s !! ��û����Ҫ�Ӽ۵ģ�",
//			   buyer->query("c_name"),
				bid_price,
			   	auc_item->query("short")));
	return 1;
	}
	else return help();
}


