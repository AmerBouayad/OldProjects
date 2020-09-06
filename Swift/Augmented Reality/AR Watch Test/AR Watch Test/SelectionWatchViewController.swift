//
//  SelectionWatchViewController.swift
//  AR Watch Test
//
//  Created by abo on 09/03/2020.
//  Copyright © 2020 abo. All rights reserved.
//

import UIKit

class SelectionWatchViewController: UIViewController, UIPickerViewDelegate, UIPickerViewDataSource {
    
    @IBOutlet weak var pickerView: UIPickerView!
    let customHeight = 250
    let customWidth = 200
    let watchCount = 3
    
    override func viewDidLoad() {
        super.viewDidLoad()
        pickerView.delegate = self
        pickerView.dataSource = self
        pickerView.transform =  CGAffineTransform(rotationAngle: (-90 * (.pi/180)))
    }
    
    func numberOfComponents(in pickerView: UIPickerView) -> Int {
        return 1
    }
    
    func pickerView(_ pickerView: UIPickerView, numberOfRowsInComponent component: Int) -> Int {
        return watchCount
    }
    
    func pickerView(_ pickerView: UIPickerView, rowHeightForComponent component: Int) -> CGFloat {
        return CGFloat(customHeight)
    }
    
    func pickerView(_ pickerView: UIPickerView, widthForComponent component: Int) -> CGFloat {
        return CGFloat(customWidth)
    }
    
    func pickerView(_ pickerView: UIPickerView, viewForRow row: Int, forComponent component: Int, reusing view: UIView?) -> UIView {
        
        let myView = UIView(frame: CGRect(x: 0, y: 0, width: customWidth, height:  customHeight))
        
        let myImageView = UIImageView(frame: CGRect(x: 0, y: 0, width: customWidth - 20, height: customHeight))
        myImageView.center.x = myView.center.x
        
        switch row {
        case 0:
            myImageView.image = UIImage(named:"watch-1.png")
        case 1:
            myImageView.image = UIImage(named:"watch-2.png")
        case 2:
            myImageView.image = UIImage(named:"watch-3.png")
        default:
            myImageView.image = nil
        }
        
        myView.addSubview(myImageView)
        myView.transform =  CGAffineTransform(rotationAngle:(90 * (.pi/180)))        
        return myView
    }
    
}
