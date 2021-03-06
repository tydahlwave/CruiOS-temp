//
//  CommunityGroup.swift
//  Cru
//
//  Created by Max Crane on 5/18/16.
//  Copyright © 2016 Jamaican Hopscotch Mafia. All rights reserved.
//

import UIKit
// FIXME: comparison operators with optionals were removed from the Swift Standard Libary.
// Consider refactoring the code to use the non-optional operators.
fileprivate func < <T : Comparable>(lhs: T?, rhs: T?) -> Bool {
  switch (lhs, rhs) {
  case let (l?, r?):
    return l < r
  case (nil, _?):
    return true
  default:
    return false
  }
}

// FIXME: comparison operators with optionals were removed from the Swift Standard Libary.
// Consider refactoring the code to use the non-optional operators.
fileprivate func > <T : Comparable>(lhs: T?, rhs: T?) -> Bool {
  switch (lhs, rhs) {
  case let (l?, r?):
    return l > r
  default:
    return rhs < lhs
  }
}


class CommunityGroup: Comparable, Equatable{

    var id: String!
    var name : String!
    var description: String!
    var meetingTime: String!
    //var leaders : [[String: AnyObject]]!
    var parentMinistry : String!
    var ministryName: String?
    var leaders = [User]()
    
    init(dict: NSDictionary) {
        id = dict["_id"] as? String
        name = dict["name"] as? String
        description = dict["description"] as? String
        if let dateStr = dict["meetingTime"] as? String {
            //the date is in a different format from other dates
            // just going to use the string for now
            meetingTime = dateStr//GlobalUtils.dateFromString(dateStr)
        }
        if let leadersDict  = dict["leaders"] as? [[String: AnyObject]]{
            for lead in leadersDict{
                leaders.append(User(dict: lead as NSDictionary))
            }
        }
        parentMinistry = dict["parentMinistry"] as? String
    }
    
    func getMeetingTime()->String{
        let format = "E h:mm a"
        let serverFormat = "E M d y H:m:s"
  
        let formatter = GlobalUtils.getDefaultDateFormatter()//NSDateFormatter()
        //formatter.dateFormat = serverFormat
        
        if (meetingTime != nil && meetingTime.characters.count > 15){
            //let parsedMeetingTime = meetingTime.substringWithRange(Range<String.Index>(start: meetingTime.startIndex, end: meetingTime.endIndex.advancedBy(-14)))
            let meetingTimeAsDate = formatter.date(from: meetingTime)
            formatter.dateFormat = format
            
            if (meetingTimeAsDate != nil){
                return formatter.string(from: meetingTimeAsDate!)
            }
            else{
                return ""
            }
        }
        else{
            return ""
        }
    }
    
}

/* Function for the Comparable & Equatable protocols */
func  < (lGroup: CommunityGroup, rGroup: CommunityGroup) -> Bool{
    if(lGroup.name < rGroup.name){
        return true
    }
    else if(lGroup.name > rGroup.name){
        return false
    }
    return false
}

func  ==(lGroup: CommunityGroup, rGroup: CommunityGroup) -> Bool{
    return lGroup.id == rGroup.id
}
