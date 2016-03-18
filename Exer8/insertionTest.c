while(current!=NULL)
	{
		
		cmp=strcmp(key->data,current->data);
		temp=current;
		current=current->next;
		temp->next=NULL;
		temp->prev=NULL;

		if(cmp<0)		//right of the key
		{
		
			insert_next=key;
			
			while(insert_next!=NULL)
			{
				cmp2=strcmp(temp->data,insert_next->data);
				if(cmp2<0)
				{
					temp->prev=insert_next->prev;
					insert_next->prev->next=temp;
					temp->next=insert_next;
					insert_next->prev=temp;
					break;
				}
				else
				{
					insert_next=insert_next->next;
				}
			}
		}
		else if(cmp>0)	//left of the key
		{
			insert_next=key;
			
			while(insert_next!=NULL)
			{
				cmp2=strcmp(temp->data,insert_next->data);
				if(cmp2<0)
				{
					temp->prev=insert_next->prev;
					insert_next->prev->next=temp;
					temp->next=insert_next;
					insert_next->prev=temp;
					break;
				}
				else
				{
					insert_next=insert_next->prev;
				}
			}
		}
		else		//if key and current are the same
		{
			if(key->next!=NULL)
			{
				temp->next=key->next;
				key->next=temp;
				temp->prev=key;
			}
			else
			{
				key->next=temp;
				temp->prev=key;
			}
		}
	
	}
