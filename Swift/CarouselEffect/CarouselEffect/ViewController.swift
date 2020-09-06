//
//  ViewController.swift
//  CarouselEffect
//
//  Created by abo on 09/03/2020.
//  Copyright © 2020 abo. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    @IBOutlet weak var collectionView: UICollectionView!
    
    @IBOutlet weak var btnSelectWatch: UIButton!
    var watches = Watch.fetchWatches()
    let collectionViewWidth = 200
    let cellWidth = 200
    let cellSpacing = 20
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        collectionView?.dataSource = self
        collectionView?.delegate = self
        btnSelectWatch.addTarget(self, action: #selector(buttonAction), for: .touchUpInside)
    }
    
    @objc func buttonAction(sender: UIButton!) {
        let center = self.view.convert(self.collectionView.center, to: self.collectionView)
        let index = collectionView!.indexPathForItem(at: center)
        print(index ?? "index not found")
        performSegue(withIdentifier: "Segueidentifier", sender: self)
    }
    
    
}

extension ViewController : UICollectionViewDataSource {
    func numberOfSections(in collectionView: UICollectionView) -> Int {
        return 1
    }
    
    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return watches.count
    }
    
    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "WatchCell", for: indexPath) as! WatchCollectionViewCell
        cell.watch = watches[indexPath.item]
        return cell
    }
    
    func collectionView(collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, insetForSectionAtIndex section: Int) -> UIEdgeInsets {
        let cellCount = watches.count
        let totalCellWidth = cellWidth * cellCount
        let totalSpacingWidth = cellSpacing * (cellCount - 1)
        
        let leftInset = (collectionViewWidth - Int(CGFloat(totalCellWidth + totalSpacingWidth))) / 2
        let rightInset = leftInset
        
        return UIEdgeInsets(top: 0, left: CGFloat(leftInset), bottom: 0, right: CGFloat(rightInset))
    }
    
}

extension ViewController : UIScrollViewDelegate, UICollectionViewDelegate {
    
    func scrollViewWillEndDragging(_ scrollView: UIScrollView, withVelocity velocity: CGPoint, targetContentOffset: UnsafeMutablePointer<CGPoint>) {
        
        let layout = self.collectionView?.collectionViewLayout as! UICollectionViewFlowLayout
        let cellWidthIncludingSpacing = layout.itemSize.width + layout.minimumLineSpacing
        
        var offset = targetContentOffset.pointee
        let index = (offset.x + scrollView.contentInset.left) / cellWidthIncludingSpacing
        let roundedIndex = round(index)
        
        offset = CGPoint(x: roundedIndex * cellWidthIncludingSpacing - scrollView.contentInset.left, y: -scrollView.contentInset.top)
        targetContentOffset.pointee = offset
    }
    
}





