//   This is std gamble lib for every thing that do anything to
//   gambling               indra@Eastern_Story 95.3.1

//   ��Ҳ���ͬʱ����������

int check_gamble(object obj)
{
   if(!(obj->query_temp("gambling")) )
      return 0 ;
   else    
      return 1 ;
} 

// ������ע�Ķ���, �ں���ǰҪ�Ƚ�Ǯ����������ɵ�һ����

int check_bet(int number,object player,int bet_time_flag)
{
   int old_bet ;
   if(!(number)||!(player)||!bet_time_flag)
      return 0 ;

   if( !(old_bet = player->query_temp("gambling/bet") ) )
       old_bet = 0 ;
         
   player->set_temp("gambling/bet",old_bet+number);
   return 1;
}
// ���趨���ĸ��ƾֵĶ���

int do_play_game(object player,string name,string play_msg,string play_msg1)
{
    player->set_temp("gambling/"+name) ;
    
    tell_object(player,sprintf("�ڶ̶̵�˼��֮��,�����ȥ��%s��\n",cname) ) ;

    tell_room( environment(),play_msg1,player ) ;
                
    return 1;

}
//  ϴ�Ƶĺ�ʽ,�봫���þߵ��ͱ�,���ظ��ĸ���(��������̫��,Ҫ�ó���һ��)

int *wash_cards(mapping card_style,int multi)
{
    int i,j , style_no , member_no , total_no , *cards_li,temp ;
    string *style_name ;
    
    total_no = 0 ;
    style_name = key(card_style) ;
    style_no = sizeof(style_name) ;
    cards_li = ({ }) ;
    
    if(!(multi)||(multi<1)) multi = 1 ;
      
    for(i=0;i<style_no;i++)    
       {
         member_no = sizeof(card_style[style_name[i]]) ;
         total_no = ( total_no + member_no ) * multi  ;        
        }  
    
    for(i=0;i<total_no;i++)
       {
         temp = random(total_no) ;
         
         for(j=0;j < i+1;j++)
            {
              if(j == i)
                { 
                  cards_li[i] = temp ; break ;
                 }
              if(temp==cards_li[j])
                {
                  --i ; break ;          
                 }
             }         
        }  
    return cards_li ;          
}


